#include "Hero.class.hpp"

Hero::Hero(void) : GameEntity('H', 0, 0, 100, 20){
	return;
}

Hero::Hero(Hero const & cpy) : GameEntity(cpy.getModel(), cpy.getRealPositionX(), cpy.getRealPositionY(), cpy.getHealth(), cpy.getDamage()){
	*this = cpy;
	return;
}

Hero::~Hero(void){
	return;
}

Hero &			Hero::operator=(Hero const & rhs){
	if (this != &rhs){
		this->setModel(rhs.getModel());
		this->setRealPositionX(rhs.getRealPositionX());
		this->setRealPositionY(rhs.getRealPositionY());
		this->setHealth(rhs.getHealth());
		this->setDamage(rhs.getDamage());
	}
	return *this;
}

Hero *			Hero::clone(void){
	return new Hero(*this);
}

void			Hero::attack(void){

}

void			Hero::takeDamage(unsigned int damage){
	this->setHealth(this->getHealth() - damage);
	if (this->getHealth() == 0){
		//die + end of game
	}
	return;
}
