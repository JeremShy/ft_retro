#include "Hero.class.hpp"
#include "display.hpp"
#include <cstdlib>
#include <iostream>
#include <sys/ioctl.h>

Hero::Hero(void) : GameEntity('H', 0, 0, 1, 20){
	return;
}

Hero::Hero(Hero const & cpy) : GameEntity(cpy.getModel(), cpy.getRealPositionX(), cpy.getRealPositionY(), cpy.getHealth(), cpy.getDamage()){
	*this = cpy;
	return;
}

Hero::~Hero(void){
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

Hero *			Hero::clone(void){
	return new Hero(*this);
}

// Bullet*		Hero::attack(void){
// 	Bullet*		bullet = new Bullet('-', this->getRealPositionX() + 1, this->getRealPositionY(), 1, this->getDamage());
// 	return bullet;
// }
//

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
	struct winsize size;
	if (ioctl(0, TIOCGWINSZ, (char *) &size) < 0)
	{
		close_ncurse();
		std::cout << "error with ioctl" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (this->_x + this->_direction[0] < 0 || this->_x + this->_direction[0] > size.ws_col - 1)
		return;
	if (this->_y + this->_direction[1] < 0 || this->_y + this->_direction[1] > size.ws_row - 1)
		return;
	this->_x += this->_direction[0];
	this->_y += this->_direction[1];
}
