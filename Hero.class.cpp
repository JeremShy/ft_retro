#include "Hero.class.hpp"
#include "display.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>

Hero::Hero(void) : GameEntity('H', 3, 20, 1, 20){
	return;
}

Hero::Hero(Hero const & cpy) : GameEntity(cpy.getModel(), cpy.getRealPositionX(), cpy.getRealPositionY(), cpy.getHealth(), cpy.getDamage()){
	*this = cpy;
	return;
}

Hero::~Hero(void){
	std::fstream log("log", std::fstream::out | std::fstream::app);
	log << "POUET POUET POUET POUET POUET POUET" << std::endl;
	return;
}

Hero &			Hero::operator=(Hero const & rhs){
	if (this != &rhs){
		this->setModel(rhs.getModel());
		this->setRealPositionX(rhs.getRealPositionX());
		this->setRealPositionY(rhs.getRealPositionY());
		this->setHealth(rhs.getHealth());
		this->setDamage(rhs.getDamage());
	}
	return *this;
}

Hero *			Hero::clone(void)
{
	return new Hero(*this);
}

void Hero::attack(void) {

}
void			Hero::takeDamage(unsigned int damage){
	this->setHealth(this->getHealth() - damage);
	if (this->getHealth() == 0){
		close_ncurse();
		std::cout << "Game Over!" << std::endl;
		exit(0);
	}
	return;
}

Bullet	*Hero::shoot(void) {
	Bullet *ret = new Bullet('=', this->getPositionX() + 1, this->getPositionY(), 1, this->getDamage());

	ret->setDirectionX(0.5);
	return (ret);
}

void				Hero::move(void) {
	if (this->_x + this->_direction[0] < 0 || this->_x + this->_direction[0] > get_size_x() - 1)
		return;
	if (this->_y + this->_direction[1] < 0 || this->_y + this->_direction[1] > get_size_y() - 1)
		return;
	this->_x += this->_direction[0];
	this->_y += this->_direction[1];
}
