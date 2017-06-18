#include "Bullet.class.hpp"
#include <fstream>
#include <iostream>

Bullet::Bullet(char model, int x, int y, unsigned int health, unsigned int damage) : GameEntity(model, x, y, health, damage) {
	return;
}

Bullet::Bullet(Bullet const & cpy) : GameEntity(cpy) {
	return;
}

Bullet & 			Bullet::operator=(Bullet const & rhs){
	if (this != &rhs){
		this->setRealPositionX(rhs.getRealPositionX());
		this->setRealPositionY(rhs.getRealPositionY());
		this->setHealth(rhs.getHealth());
		this->setDamage(rhs.getDamage());
		this->setModel(rhs.getModel());
	}
	return *this;
}

Bullet *			Bullet::clone(void){
	return new Bullet(*this);
}

Bullet::~Bullet(void){
	std::fstream log("log", std::fstream::out | std::fstream::app);
	log << "A bullet disappeared" << std::endl;
	log.close();
	return;
}

void				Bullet::takeDamage(unsigned int damage){
	if (this->_health - damage > 0){
		this->_health -= damage;
	} else {
		this->_health = 0;
	}
}
