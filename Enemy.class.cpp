#include "Enemy.class.hpp"

Enemy::Enemy(char model, unsigned int health, unsigned int damage) : GameEntity(model){
	this->setHealth(health);
	this->setDamage(damage);
	return;
}

Enemy::Enemy(Enemy const & cpy) : GameEntity(cpy.getModel()){
	*this = cpy;
	return;
}

Enemy::~Enemy(void){
	return;
}

Enemy &			Enemy::operator=(Enemy const & rhs){
	if (this != &rhs){
		this->setModel(rhs.getModel());
		this->setPositionX(rhs.getPositionX());
		this->setPositionY(rhs.getPositionY());
		this->setHealth(rhs.getHealth());
		this->setDamage(rhs.getDamage());
	}
	return *this;
}

Enemy *			Enemy::clone(void){
	return new Enemy(*this);
}

void			Enemy::attack(void) const{
	// Do enemies attack ?
}

void			Enemy::takeDamage(unsigned int damage){
	this->setHealth(this->getDamage() - damage);
	if (this->getHealth() == 0){
		delete this;
		this = NULL;
	}
	return;
}