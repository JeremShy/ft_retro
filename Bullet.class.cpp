#include "Bullet.class.hpp"

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
	return;
}

void				Bullet::attack(void){};

void				Bullet::takeDamage(unsigned int damage){
	this->setHealth(this->getHealth() - damage);
}