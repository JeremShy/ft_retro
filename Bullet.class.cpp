#include "Bullet.class.hpp"

Bullet::Bullet(int x, int y, int damage, GameEntity * shooter) : AMovable(x, y), _damage(damage), _shooter(shooter){
	return;
}

Bullet::Bullet(Bullet const & cpy) : AMovable(cpy.getRealPositionX(), cpy.getRealPositionY()), _damage(cpy.getDamage()), _shooter(cpy.getShooter()){
	return;
}

Bullet & 			Bullet::operator=(Bullet const & rhs){
	if (this != &rhs){
		this->setRealPositionX(rhs.getRealPositionX());
		this->setRealPositionY(rhs.getRealPositionY());
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

/*--------------------------------------------setter*/

void				Bullet::setDamage(int damage){
	this->_damage = damage;
	return;
}

void				Bullet::setShooter(GameEntity * shooter){
	this->_shooter = shooter;
	return;
}

/*--------------------------------------------getter*/

int					Bullet::getDamage(void) const{
	return this->_damage;
}

GameEntity *		Bullet::getShooter(void) const{
	return this->_shooter;
}
