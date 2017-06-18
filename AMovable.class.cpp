#include "AMovable.class.hpp"
#include <unistd.h>
#include <fstream>

AMovable::AMovable(void) : _x(0), _y(0), _health(0), _damage(0) {
	(this->_direction)[0] = 0;
	(this->_direction)[1] = 0;
}

AMovable::AMovable(AMovable const & src) : _x(src._x), _y(src._y) {
	(this->_direction)[0] = (src._direction)[0];
	(this->_direction)[1] = (src._direction)[1];
}

AMovable::AMovable(int x, int y, unsigned int health, unsigned int damage) : _x(x), _y(y), _health(health), _damage(damage) {
	// std::cout << "HERE : " << x << " - " << y << std::endl;
	(this->_direction)[0] = 0;
	(this->_direction)[1] = 0;
}

AMovable::~AMovable(void) {

}

AMovable & AMovable::operator=(AMovable const & rhs) {
	this->_x = rhs._x;
	this->_y = rhs._y;
	(this->_direction)[0] = (rhs._direction)[0];
	(this->_direction)[1] = (rhs._direction)[1];
	return (*this);
}

void				AMovable::move(void) {
	this->_x += this->_direction[0];
	this->_y += this->_direction[1];
}

void				AMovable::setPositionX(unsigned int x){
	this->_x = x;
	return;
}

void				AMovable::setPositionY(unsigned int y){
	this->_y = y;
	return;
}


void 				AMovable::setRealPositionX(float x) {
	this->_x = x;
	return;
}

void 				AMovable::setRealPositionY(float y) {
	this->_y = y;
	return;
}


void			AMovable::setDirection(float tab[2]) {
	this->_direction[0] = tab[0];
	this->_direction[1] = tab[0];
}

void			AMovable::setDirectionX(float x) {
	this->_direction[0] = x;
}

void			AMovable::setDirectionY(float y) {
	this->_direction[1] = y;
}


unsigned int		AMovable::getPositionX(void) const{
	return this->_x;
}

unsigned int		AMovable::getPositionY(void) const{
	return this->_y;
}

float 				AMovable::getRealPositionX(void) const {
	return (this->_x);
}
float 				AMovable::getRealPositionY(void) const {
	return (this->_y);
}
bool				AMovable::doesCollide(AMovable *obj){
	if (this->getPositionX() == obj->getPositionX() && this->getPositionY() == obj->getPositionY())
	{
		std::fstream log("log", std::fstream::out | std::fstream::app);
		log << "A collision was detected !" << std::endl;
		log.close();
		return true;
	}
	return false;
}
unsigned int 		AMovable::getHealth(void) const{
	return this->_health;
}
unsigned int 		AMovable::getDamage(void) const{
	return this->_damage;
}
void				AMovable::setHealth(unsigned int health){
	this->_health = health;
}
void				AMovable::setDamage(unsigned int damage){
	this->_damage = damage;
}
