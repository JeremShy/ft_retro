#include "GameEntity.class.hpp"
#include "display.hpp"
#include <fstream>

GameEntity::GameEntity(char model, unsigned int x = 0, unsigned int y = 0, unsigned int health = 0, unsigned int damage = 0) : _x(x), _y(y), _health(health), _damage(damage) , _model(model){
	this->_direction[0] = 0;
	this->_direction[1] = 0;
	return;
}

GameEntity::GameEntity(GameEntity const & cpy) : _x(cpy.getRealPositionX()), _y(cpy.getRealPositionY()), _health(cpy.getHealth()), _damage(cpy.getDamage()), _model(cpy.getModel()){
	this->_direction[0] = 0;
	this->_direction[1] = 0;
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
		this->_direction[0] = 0;
		this->_direction[1] = 0;
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

unsigned int 		GameEntity::getHealth(void) const{
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

void				GameEntity::setPositionX(unsigned int x){
	this->_x = x;
	return;
}

void				GameEntity::setPositionY(unsigned int y){
	this->_y = y;
	return;
}


void 				GameEntity::setRealPositionX(float x) {
	this->_x = x;
	return;
}

void 				GameEntity::setRealPositionY(float y) {
	this->_y = y;
	return;
}


void			GameEntity::setDirection(float tab[2]) {
	this->_direction[0] = tab[0];
	this->_direction[1] = tab[0];
}

void			GameEntity::setDirectionX(float x) {
	this->_direction[0] = x;
}

void			GameEntity::setDirectionY(float y) {
	this->_direction[1] = y;
}


unsigned int		GameEntity::getPositionX(void) const{
	return this->_x;
}

unsigned int		GameEntity::getPositionY(void) const{
	return this->_y;
}

float 				GameEntity::getRealPositionX(void) const {
	return (this->_x);
}
float 				GameEntity::getRealPositionY(void) const {
	return (this->_y);
}

bool				GameEntity::doesCollide(GameEntity *obj){
	if (this->getPositionX() == obj->getPositionX() && this->getPositionY() == obj->getPositionY())
	{
		std::fstream log("log", std::fstream::out | std::fstream::app);
		log << "A collision was detected !" << std::endl;
		log.close();
		return true;
	}
	return false;
}
