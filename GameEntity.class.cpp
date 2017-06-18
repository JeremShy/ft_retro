#include "GameEntity.class.hpp"
#include "display.hpp"
#include <fstream>

GameEntity::GameEntity(char model, unsigned int x = 0, unsigned int y = 0, unsigned int health = 0, unsigned int damage = 0) : AMovable(x, y, health, damage), _model(model){
	return;
}

GameEntity::GameEntity(GameEntity const & cpy) : AMovable(cpy.getRealPositionX(), cpy.getRealPositionY(), cpy.getHealth(), cpy.getDamage()), _model(cpy.getModel()){
	return;
}

GameEntity::~GameEntity(void){
	return;
}

GameEntity & 		GameEntity::operator=(GameEntity const & rhs){
	if (this != &rhs){
		this->setModel(rhs.getModel());
		this->setRealPositionX(rhs.getRealPositionX());
		this->setRealPositionY(rhs.getRealPositionY());
		this->setHealth(rhs.getHealth());
		this->setDamage(rhs.getDamage());
	}
	return *this;
}

GameEntity *		GameEntity::clone(void){
	return new GameEntity(*this);
}

void					GameEntity::takeDamage(unsigned int amount) {
	//Maybe decrement with the armor of the GE.
	//
	std::fstream log("log", std::fstream::out | std::fstream::app);
	log << "A GameEntity took " << amount << " damages." << std::endl;
	log.close();
	if (amount >= this->getHealth()) {
		this->setHealth(0);
		return ;
	}
	this->setHealth(this->getHealth() - amount);
}

/*-----------------------------------------------------------getter*/

char				GameEntity::getModel(void) const{
	return this->_model;
}

int					GameEntity::getPositionX(void) const{
	return this->_x;
}

int					GameEntity::getPositionY(void) const{
	return this->_y;
}

unsigned int 		GameEntity::getHeath(void) const{
	return this->_health;
}

unsigned int		GameEntity::getDamage(void) const{
	return this->_damage;
}

/*-----------------------------------------------------------setter*/

void				GameEntity::setModel(char model){
	this->_model = model;
	return;
}

void				GameEntity::setPositionX(int x){
	this->_x = x;
	return;
}

void				GameEntity::setPositionY(int y){
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

void				GameEntity::display(void) {
	mvaddch(this->getPositionY(), this->getPositionX(), this->getModel());
}

void				GameEntity::erase(void) {
	mvdelch(this->getPositionY(), this->getPositionX());
}
