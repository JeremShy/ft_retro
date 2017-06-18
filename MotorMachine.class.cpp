#include "MotorMachine.class.hpp"
#include <iostream>
#include <unistd.h>

MotorMachine::MotorMachine(void) : _tab(NULL), _amount(0){
}

MotorMachine::MotorMachine(MotorMachine const & src) : _amount(src._amount){
	if (this->_tab)
		delete [] this->_tab;
	this->_tab = new AMovable*[src._amount];
	for (unsigned int i = 0; i < src._amount; i++) {
		this->_tab[i] = src._tab[i]->clone();
	}
}

MotorMachine::~MotorMachine(void) {
	if (this->_tab)
		delete [] this->_tab;
}

MotorMachine & MotorMachine::operator=(MotorMachine const & rhs) {
	if (this->_tab)
		delete [] this->_tab;
	this->_amount = rhs._amount;
	this->_tab = new AMovable*[rhs._amount];
	for (unsigned int i = 0; i < rhs._amount; i++) {
		this->_tab[i] = rhs._tab[i]->clone();
	}
	return (*this);
}

void	MotorMachine::moveAll(void) {
	for (unsigned int i = 0; i < this->_amount; i++) {
		// std::cout << "i : " << i << std::endl;
		(this->_tab[i])->move();
		for (unsigned int y = 0; y < this->_amount; y++) {
			if (y != i){
				if ((this->_tab[i])->doesCollide(this->_tab[y])){
					// do something
				}
			}
		}
	}
}

void	MotorMachine::moveAllExcept(AMovable *obj) {
	for (unsigned int i = 0; i < this->_amount; i++) {
		// std::cout << "i : " << i << std::endl;
		if (this->_tab[i] != obj){
			(this->_tab[i])->move();
			for (unsigned int y = 0; y < this->_amount; y++) {
				if (y != i){
					if ((this->_tab[i])->doesCollide(this->_tab[y])){
						// do something
					}
				}
			}
		}
	}
}

void	MotorMachine::addMovable(unsigned int idx, AMovable *obj) { // TO DO : Tester quand les iprintable seront fonctionels.
	if (idx > this->_amount + 1) {
		std::cout << "There was an error while trying to ADD a movable on the MotorMachine at position " << idx << ". There are only " << this->_amount << " movables in the table." << std::endl;
		return ;
	}
	// std::cout << "id : " << idx << std::endl;
	if (this->_amount == 0) {
		if (this->_tab != NULL) { //_tab is supposed to be null if _amount == 0, but still..
			delete [] this->_tab;
		}
		this->_tab = new AMovable*[1];
		this->_tab[0] = obj;
		this->_amount = 1;
		return ;
	}

	AMovable **new_tab = new AMovable*[this->_amount + 1];
	unsigned int i;

	for (i = 0; i < idx; i++) {
		new_tab[i] = this->_tab[i];
	}
	new_tab[i] = obj;
	i++;
	for (; i < this->_amount; i++) {
		new_tab[i] =this->_tab[i - 1];
	}
	delete [] this->_tab;
	this->_tab = new_tab;
	this->_amount++;
}

void	MotorMachine::addMovable(AMovable *obj) {
	this->addMovable(this->_amount, obj);
}

void	MotorMachine::removeMovable(unsigned int idx) {
	if (idx >= this->_amount) {
		std::cout << "There was an error while trying to REMOVE a movable on the MotorMachine at position " << idx << ". There are only " << this->_amount << " movables in the table." << std::endl;
		return ;
	}

	AMovable		**new_tab = new AMovable*[this->_amount - 1];
	unsigned int	i;

	for (i = 0; i < idx ; i++) {
		new_tab[i] = this->_tab[i];
	}
	i++;
	for (; i < this->_amount; i++) {
		new_tab[i - 1] = this->_tab[i];
	}
	if (this->_tab)
		delete [] this->_tab;
	else
		std::cout << "You aren't supposed to be here. There probably was an error.. " << std::endl;
	this->_tab = new_tab;
	this->_amount--;
}

void	MotorMachine::removeMovable(AMovable *obj) {
	for (unsigned int i = 0; i < this->_amount; i++) {
		if (this->_tab[i] == obj) {
			std::cout << "Object found at position " << i <<std::endl;
			this->removeMovable(i);
			return ;
		}
	}
	std::cout << "There was an error while trying to REMOVE a movable." << std::endl;
}

AMovable	*MotorMachine::getMovable(unsigned int idx) {
	if (idx >= this->_amount) {
		std::cout << "There was an error while trying to GET a movable on the MotorMachine at position " << idx << ". There are only " << this->_amount << " printables in the table. Returning NULL." << std::endl;
		return NULL;
	}
	return (this->_tab[idx]);
}

unsigned int	MotorMachine::getAmount(void) const {
	return (this->_amount);
}

void					MotorMachine::describe() {
	for (unsigned int i = 0; i < this->_amount; i++) {
		std::cout << "[" << i << "] : " << this->_tab[i] << std::endl;
	}
}

/*void					MotorMachine::collide(RenderMachine &rmachine, GameEntity** props, int amount){
	for (int i = 0; i < amount; i++){
		for (int y = i + 1; y < amount; y++){
			if (props[i] != NULL && props[y] != NULL){
				if (props[i]->getPositionX() == props[y]->getPositionX() && props[i]->getPositionY() == props[y]->getPositionY()){
					props[i]->takeDamage(props[y]->getDamage());
					props[y]->takeDamage(props[i]->getDamage());
					std::cout << "props[i]" << props[i]->getHealth() << " | props[y] " << props[y]->getHealth();
					sleep(1);
					if (props[i]->getHealth() == 0){
						this->removeMovable(props[i]);
						rmachine.removePrintable(props[i]);
						delete props[i];
						props[i] = NULL;
					}
					if (props[y]->getHealth() == 0){
						this->removeMovable(props[y]);
						rmachine.removePrintable(props[y]);
						delete props[y];
						props[y] = NULL;
					}
				}
			}
		}
	}
}*/