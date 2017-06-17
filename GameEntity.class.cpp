#include "GameEntity.class.hpp"

GameEntity::GameEntity(char model, unsigned int x = 0, unsigned int y = 0, unsigned int health = 0, unsigned int damage = 0) : _model(model), _x(x), _y(y), _health(health), _damage(damage){
	return;
}

GameEntity::GameEntity(GameEntity const & cpy) : _model(cpy.getModel()), _x(cpy.getPositionX()), _y(cpy.getPositionY()), _health(cpy.getHealth()), _damage(cpy.getDamage()){
	return;
}

GameEntity::~GameEntity(void){
	return;
}

GameEntity & 		GameEntity::operator=(GameEntity const & rhs){
	if (this != &rhs){
		this->setModel(rhs.getModel());
		this->setPositionX(rhs.getPositionX());
		this->setPositionY(rhs.getPositionY());
		this->setHealth(rhs.getHealth());
		this->setDamage(rhs.getDamage());
	}
	return *this;
}

void				GameEntity::takeDamage(unsigned int damage){
	this->setHealth(this->getDamage() - damage);
	if (this->getHealth() <= 0) {
		// die
	}
	return;
}

/*-----------------------------------------------------------getter*/

char				GameEntity::getModel(void) const{
	return this->_model;
}

unsigned int		GameEntity::getPositionX(void) const{
	return this->_x;
}

unsigned int		GameEntity::getPositionY(void) const{
	return this->_y;
}

unsigned int 		GameEntity::getHealth(void) const{
	return this->_health;
}

unsigned int 		GameEntity::getDamage(void) const{
	return this->_damage;
}

/*-----------------------------------------------------------setter*/

void				GameEntity::setModel(char model){
	this->_model = model;
	return;
}

void				GameEntity::setPositionX(unsigned int x){
	this->_x = x;
	return;
}

void				GameEntity::setPositionY(unsigned int y){
	this->_y = y;
	return;
}

void				GameEntity::setHealth(unsigned int health){
	this->_health = health;
	return;
}

void				GameEntity::setDamage(unsigned int damage){
	this->_damage = damage;
	return;
}
