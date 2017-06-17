#include "Enemy.class.hpp"

Enemy::Enemy(char model, unsigned int health, unsigned int damage) : GameEntity(model, 0, 0, health, damage) { // TODO : Default value for x and y or require x and y as parameter
	this->setHealth(health);
	this->setDamage(damage);
	return;
}

Enemy::Enemy(Enemy const & cpy) : GameEntity(cpy.getModel(), cpy.getPositionX(), cpy.getPositionY(), cpy.getHealth(), cpy.getDamage()){
	// *this = cpy;
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

void			Enemy::attack(void){
	// Do enemies attack ?
}

void			Enemy::takeDamage(unsigned int damage){
	this->setHealth(this->getDamage() - damage);
	if (this->getHealth() == 0){
		delete this;
	}
	return;
}

void			Enemy::move(int input=-1){
	if (input == -1)
		this->setPositionX(this->getPositionX() - 1);
	return;
}

std::ostream& operator<< (std::ostream& stream, const Enemy & enemy) {
	stream << enemy.getModel() << ": has " << enemy.getHealth() << "hp and deals " << enemy.getDamage() << " damage." << std::endl;
	return (stream);
}
