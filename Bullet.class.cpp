#include "Bullet.class.hpp"

Bullet::Bullet(int x, int y, int damage, GameEntity * shooter) : _x(x), _y(y), _damage(damage), _shooter(shooter){
	return;
}

Bullet::Bullet(Bullet const & cpy) : _x(cpy.getPositionX()), _y(cpy.getPositionY()), _damage(cpy.getDamage()), _shooter(cpy.getShooter()){
	return;
}

Bullet & 			Bullet::operator=(Bullet const & rhs){
	if (this != &rhs){
		this->setPositionX(rhs.getPositionX());
		this->setPositionY(rhs.getPositionY());
		this->setDamage(rhs.getDamage());
		this->setShooter(rhs.getShooter());
	}
	return *this;
}

Bullet *			Bullet::clone(void){
	return new Bullet(*this);
}

Bullet::~Bullet(void){
	return;
}

void				Bullet::display(void){
	/* do something */
}

void				Bullet::erase(void){
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

void				Bullet::setShooter(GameEntity * shooter){
	this->_shooter = shooter;
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

GameEntity *		Bullet::getShooter(void) const{
	return this->_shooter;
}
