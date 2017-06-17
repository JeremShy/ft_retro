#include "EnemyA.class.hpp"

EnemyA::EnemyA(void) : Enemy('A', 10, 0){
	return;
}

EnemyA::EnemyA(EnemyA const & cpy) : Enemy(cpy){
	return;
}

EnemyA::~EnemyA(void){
	return;
}

EnemyA &		EnemyA::operator=(EnemyA const & rhs){
	if (this != &rhs){
		this->setModel(rhs.getModel());
		this->setPositionX(rhs.getPositionX());
		this->setPositionY(rhs.getPositionY());
		this->setHealth(rhs.getHealth());
		this->setDamage(rhs.getDamage());
	}
	return *this;
}
