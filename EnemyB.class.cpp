#include "EnemyB.class.hpp"

EnemyB::EnemyB(void) : Enemy('B', 35, 0){
	return;
}

EnemyB::EnemyB(EnemyB const & cpy) : Enemy(cpy.getModel(), cpy.getHealth(), cpy.getDamage()){
	return;
}

EnemyB::~EnemyB(void){
	return;
}

EnemyB &		EnemyB::operator=(EnemyB const & rhs){
	if (this != &rhs){
		this->setModel(rhs.getModel());
		this->setPositionX(rhs.getPositionX());
		this->setPositionY(rhs.getPositionY());
		this->setHealth(rhs.getHealth());
		this->setDamage(rhs.getDamage());
	}
	return *this;
}