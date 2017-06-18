#include "Enemy.class.hpp"

Enemy::Enemy(char model, unsigned int health, unsigned int damage) : GameEntity(model, 0, 0, health, damage) { // TODO : Default value for x and y or require x and y as parameter
	this->setHealth(health);
	this->setDamage(damage);
	return;
}

Enemy::Enemy(Enemy const & cpy) : GameEntity(cpy){
	// *this = cpy;
	return;
}

Enemy::~Enemy(void){
	return;
}

Enemy &			Enemy::operator=(Enemy const & rhs){
	if (this != &rhs){
		this->setModel(rhs.getModel());
		this->setRealPositionX(rhs.getRealPositionX());
		this->setRealPositionY(rhs.getRealPositionY());
		this->setHealth(rhs.getHealth());
		this->setDamage(rhs.getDamage());
	}
	return *this;
}

Enemy *			Enemy::clone(void){
	return new Enemy(*this);
}

// void			Enemy::takeDamage(unsigned int damage){
// 	this->setHealth(this->getDamage() - damage);
// 	if (this->getHealth() == 0){
// 		delete this;
// 	}
// 	return;
// }

std::ostream& operator<< (std::ostream& stream, const Enemy & enemy) {
	stream << enemy.getModel() << ": has " << enemy.getHealth() << "hp and deals " << enemy.getDamage() << " damage." << std::endl;
	return (stream);
}
