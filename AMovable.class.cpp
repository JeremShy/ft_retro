#include "AMovable.class.hpp"

AMovable::AMovable(void) : _x(0), _y(0) {
	(this->_direction)[0] = 0;
	(this->_direction)[1] = 0;
}

AMovable::AMovable(AMovable const & src) : _x(src._x), _y(src._y) {
	(this->_direction)[0] = (src._direction)[0];
	(this->_direction)[1] = (src._direction)[1];
}

AMovable::AMovable(int x, int y) : _x(x), _y(y) {

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

void			AMovable::setDirection(unsigned int tab[2]) {
	this->_direction[0] = tab[0];
	this->_direction[1] = tab[0];
}

void			AMovable::setDirectionX(unsigned int x) {
	this->_direction[0] = x;
}

void			AMovable::setDirectionY(unsigned int y) {
	this->_direction[1] = y;
}


unsigned int		AMovable::getPositionX(void) const{
	return this->_x;
}

unsigned int		AMovable::getPositionY(void) const{
	return this->_y;
}
