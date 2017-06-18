#include <iostream>
#include <fstream>
#include "GameMachine.class.hpp"

GameMachine::GameMachine(void) : _tab(NULL), _amount(0){
}

GameMachine::GameMachine(GameMachine const & src) : _amount(src._amount){
	if (this->_tab)
		delete [] this->_tab;
	this->_tab = new GameEntity*[src._amount];
	for (unsigned int i = 0; i < src._amount; i++) {
		this->_tab[i] = src._tab[i]->clone();
	}
}

GameMachine::~GameMachine(void) {
	if (this->_tab)
		delete [] this->_tab;
}

GameMachine & GameMachine::operator=(GameMachine const & rhs) {
	if (this->_tab)
		delete [] this->_tab;
	this->_amount = rhs._amount;
	this->_tab = new GameEntity*[rhs._amount];
	for (unsigned int i = 0; i < rhs._amount; i++) {
		this->_tab[i] = rhs._tab[i]->clone();
	}
	return (*this);
}

void	GameMachine::renderAll(void) {
	for (unsigned int i = 0; i < this->_amount; i++) {
		(this->_tab[i])->display();
	}
}

void	GameMachine::eraseAll(void) {
	for (unsigned int i = 0; i < this->_amount; i++) {
		// std::cout << "i : " << i << std::endl;
		(this->_tab[i])->erase();
	}
}

void	GameMachine::moveAll() {
	std::fstream log("log", std::fstream::out | std::fstream::app);
	for (unsigned int i = 0; i < this->getAmount(); i++) {
		(this->_tab[i])->move();
		for (unsigned int y = 0; y < this->getAmount(); y++) {
			if (y != i && this->_tab[i] != NULL && this->_tab[y] != NULL){
				if ((this->_tab[i])->doesCollide(this->_tab[y])){

					GameEntity* 	ptr = this->_tab[y];

					this->_tab[i]->takeDamage(this->_tab[y]->getDamage());
					this->_tab[y]->takeDamage(this->_tab[i]->getDamage());

					if (this->_tab[i]->getHealth() == 0){
						log << "trying to remove item at " << this->_tab[i] << ". (first if)" << std::endl;
						GameEntity*	ptr2 = this->_tab[i];
						this->removeGE(this->_tab[i]);
						delete ptr2;
					}

					if (ptr->getHealth() == 0){
						log << "trying to remove item at " << ptr << ". (second if)" << std::endl;
						this->removeGE(ptr);
						delete ptr;
					}
				}
			}
		}
	}
	log.close();
}

void	GameMachine::moveAllExcept(GameEntity *obj) {
	std::fstream log("log", std::fstream::out | std::fstream::app);
	for (unsigned int i = 0; i < this->getAmount(); i++) {
		// std::cout << "i : " << i << std::endl;
		if (this->_tab[i] != obj && this->_tab[i] != NULL){
			(this->_tab[i])->move();
			for (unsigned int y = 0; y < this->getAmount(); y++) {
				if (y != i && this->_tab[i] != NULL && this->_tab[y] != NULL){
					if ((this->_tab[i])->doesCollide(this->_tab[y])){

						GameEntity* 	ptr = this->_tab[y];

						this->_tab[i]->takeDamage(this->_tab[y]->getDamage());
						this->_tab[y]->takeDamage(this->_tab[i]->getDamage());

						if (this->_tab[i]->getHealth() == 0){
							log << "trying to remove item at " << this->_tab[i] << ". (first if)" << std::endl;
							GameEntity*	ptr2 = this->_tab[i];
							this->removeGE(this->_tab[i]);
							delete ptr2;
						}

						if (ptr->getHealth() == 0){
							log << "trying to remove item at " << ptr << ". (second if)" << std::endl;
							this->removeGE(ptr);
							delete ptr;
						}
					}
				}
			}
		}
	}
	log.close();
}


void	GameMachine::addGE(unsigned int idx, GameEntity *obj) {
	if (idx > this->_amount + 1) {
		std::cout << "There was an error while trying to ADD a Game Entity on the GameMachine at position " << idx << ". There is only " << this->_amount << " printables in the table." << std::endl;
		return ;
	}
	if (this->_amount == 0) {
		if (this->_tab != NULL) { //_tab is supposed to be null if _amount == 0, but still..
			delete [] this->_tab;
		}
		this->_tab = new GameEntity*[1];
		this->_tab[0] = obj;
		this->_amount = 1;
		return ;
	}
	GameEntity **new_tab = new GameEntity*[this->_amount + 1];
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

void	GameMachine::addGE(GameEntity *obj) {
	std::fstream log("log", std::fstream::out | std::fstream::app);
	this->describe();
	log << "Trying to add a Game Entity [" << obj << "] at the end of the pile" << std::endl;

	this->addGE(this->_amount, obj);
	this->describe();
	log << "-------------------" << std::endl;
	log.close();
}

void	GameMachine::removeGE(unsigned int idx) {
	std::fstream log("log", std::fstream::out | std::fstream::app);
	this->describe();
	log << "Trying to remove Game Entity at " << idx << std::endl;
	if (idx >= this->_amount) {
		log << "There was an error while trying to REMOVE a Game Entity on the GameMachine at position " << idx << ". There is only " << this->_amount << " printables in the table." << std::endl;
		log.close();
		return ;
	}

	GameEntity		**new_tab = new GameEntity*[this->_amount - 1];
	unsigned int	i;

	for (i = 0; i < idx; i ++) {
		new_tab[i] =this->_tab[i];
	}
	i++;
	for (; i < this->_amount; i++) {
		new_tab[i - 1] = this->_tab[i];
	}
	if (this->_tab)
		delete [] this->_tab;
	else
		log << "You aren't supposed to be here. There probably was an error.. " << std::endl;
	this->_tab = new_tab;
	this->_amount--;
	log.close();
	this->describe();
}

void	GameMachine::removeGE(GameEntity *obj) {
	for (unsigned int i = 0; i < this->_amount; i++) {
		if (this->_tab[i] == obj) {
			this->removeGE(i);
			return ;
		}
	}
	std::cout << "There was an error while trying to REMOVE a Game Entity." << std::endl;
}

GameEntity	*GameMachine::getGE(unsigned int idx) {
	if (idx >= this->_amount) {
		std::cout << "There was an error while trying to GET a Game Entity on the GameMachine at position " << idx << ". There is only " << this->_amount << " printables in the table. Returning NULL." << std::endl;
		return NULL;
	}
	return (this->_tab[idx]);
}

GameEntity **GameMachine::getGEAll(void){
	return this->_tab;
}

unsigned int	GameMachine::getAmount(void) const {
	return (this->_amount);
}

void					GameMachine::describe() {
	std::fstream log("log", std::fstream::out | std::fstream::app);
	log << "Describing printables" << std::endl;
	for (unsigned int i = 0; i < this->_amount; i++) {
		log << "[" << i << "] : " << this->_tab[i] << std::endl;
	}
	log.close();
}
