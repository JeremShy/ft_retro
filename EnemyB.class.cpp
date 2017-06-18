#include "EnemyB.class.hpp"

EnemyB::EnemyB(void) : Enemy('I', 30, 1){
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
		this->setRealPositionX(rhs.getRealPositionX());
		this->setRealPositionY(rhs.getRealPositionY());
		this->setHealth(rhs.getHealth());
		this->setDamage(rhs.getDamage());
	}
	return *this;
}
