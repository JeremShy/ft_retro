#include "Bullet.class.hpp"

Bullet::Bullet(int x, int y, int damage) : _x(x), _y(y), _damage(damage){
	return;
}

Bullet::Bullet(Bullet const & cpy) : _damage(cpy.getDamage()){
	return;
}

Bullet & 			Bullet::operator=(Bullet const & rhs){
	if (this != &rhs){
		this->setPositionX(rhs.getPositionX());
		this->setPositionY(rhs.getPositionY());
		this->setDamage(rhs.getDamage());
	}
	return *this;
}

Bullet *			Bullet::clone(void){
	return new Bullet(*this);
}

Bullet::~Bullet(void){
	return;
}

void				Bullet::display(void) const{
	/* do something */
}

void				Bullet::move(void){
	this->setPositionX(this->getPositionX() + 1);
	return;
}

/*--------------------------------------------setter*/

void				Bullet::setPositionX(int x){
	this->_x = x;
	return;
}

void				Bullet::setPositionY(int y){
	this->_y = y;
	return;
}

void				Bullet::setDamage(int damage){
	this->_damage = damage;
	return;
}

/*--------------------------------------------getter*/

int					Bullet::getPositionX(void) const{
	return this->_x;
}

int					Bullet::getPositionY(void) const{
	return this->_y;
}

int					Bullet::getDamage(void) const{
	return this->_damage;
}