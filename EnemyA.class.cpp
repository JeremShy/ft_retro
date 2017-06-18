#include "EnemyA.class.hpp"

EnemyA::EnemyA(void) : Enemy('X', 1, 1){
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
		this->setRealPositionX(rhs.getRealPositionX());
		this->setRealPositionY(rhs.getRealPositionY());
		this->setHealth(rhs.getHealth());
		this->setDamage(rhs.getDamage());
	}
	return *this;
}
