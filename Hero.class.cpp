#include "Hero.class.hpp"

Hero::Hero(void) : GameEntity('H', 0, 0, 100, 20){
	return;
}

Hero::Hero(Hero const & cpy) : GameEntity(cpy.getModel(), cpy.getPositionX(), cpy.getPositionY(), cpy.getHealth(), cpy.getDamage()){
	*this = cpy;
	return;
}

Hero::~Hero(void){
	return;
}

Hero &			Hero::operator=(Hero const & rhs){
	if (this != &rhs){
		this->setModel(rhs.getModel());
		this->setPositionX(rhs.getPositionX());
		this->setPositionY(rhs.getPositionY());
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

// void			Hero::move(int input){
// 	switch (input){
// 		case UP_ARROW :
// 			this->setPositionY(this->getPositionY() + 1);
// 			break;
// 		case DOWN_ARROW :
// 			this->setPositionY(this->getPositionY() - 1);
// 			break;
// 		case RIGHT_ARROW :
// 			this->setPositionX(this->getPositionX() + 1);
// 			break;
// 		case LEFT_ARROW :
// 			this->setPositionX(this->getPositionX() - 1);
// 			break;
// 	}
// }
