#include "Movable.class.hpp"

Movable::Movable(void) : _x(0), _y(0) {
	(this->_direction)[0] = 0;
	(this->_direction)[1] = 0;
}

Movable::Movable(Movable const & src) : _x(src._x), _y(src._y) {
	(this->_direction)[0] = (src._direction)[0];
	(this->_direction)[1] = (src._direction)[1];
}

Movable::Movable(int x, int y) : _x(x), _y(y) {

}

Movable::~Movable(void) {

}

Movable & Movable::operator=(Movable const & rhs) {
	this->_x = rhs._x;
	this->_y = rhs._y;
	(this->_direction)[0] = (rhs._direction)[0];
	(this->_direction)[1] = (rhs._direction)[1];
	return (*this);
}

void				Movable::move(void) {
	this->_x += this->_direction[0];
	this->_y += this->_direction[1];
}

void				Movable::setPositionX(unsigned int x){
	this->_x = x;
	return;
}

void				Movable::setPositionY(unsigned int y){
	this->_y = y;
	return;
}

void			Movable::setDirection(unsigned int tab[2]) {
	this->_direction[0] = tab[0];
	this->_direction[1] = tab[0];
}

void			Movable::setDirectionX(unsigned int x) {
	this->_direction[0] = x;
}

void			Movable::setDirectionY(unsigned int y) {
	this->_direction[1] = y;
}


unsigned int		Movable::getPositionX(void) const{
	return this->_x;
}

unsigned int		Movable::getPositionY(void) const{
	return this->_y;
}
