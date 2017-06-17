#include "EnemyA.class.hpp"

EnemyA::EnemyA(void) : Enemy((char)this->c_model, this->c_health, this->c_damage){
	return;
}

EnemyA::EnemyA(Enemy const & cpy) : Enemy(cpy.getModel(), cpy.getHealth(), cpy.getDamage()){
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