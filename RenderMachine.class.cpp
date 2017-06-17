#include "RenderMachine.class.hpp"
#include <iostream>

RenderMachine::RenderMachine(void) : _tab(NULL), _amount(0){
}

RenderMachine::RenderMachine(RenderMachine const & src) : _amount(src._amount){
	if (this->_tab)
		delete [] this->_tab;
	this->_tab = new IPrintable*[src._amount];
	for (unsigned int i = 0; i < src._amount; i++) {
		this->_tab[i] = src._tab[i]->clone();
	}
}

RenderMachine::~RenderMachine(void) {
	if (this->_tab)
		delete [] this->_tab;
}

RenderMachine & RenderMachine::operator=(RenderMachine const & rhs) {
	if (this->_tab)
		delete [] this->_tab;
	this->_amount = rhs._amount;
	this->_tab = new IPrintable*[rhs._amount];
	for (unsigned int i = 0; i < rhs._amount; i++) {
		this->_tab[i] = rhs._tab[i]->clone();
	}
	return (*this);
}

void	RenderMachine::renderAll(void) {
	for (unsigned int i = 0; i < this->_amount; i++) {
		// std::cout << "i : " << i << std::endl;
		(this->_tab[i])->display();
	}
}

void	RenderMachine::addPrintable(unsigned int idx, IPrintable *obj) { // TO DO : Tester quand les iprintable seront fonctionels.
	if (idx > this->_amount + 1) {
		std::cout << "There was an error while trying to ADD a printable on the RenderMachine at position " << idx << ". There is only " << this->_amount << " printables in the table." << std::endl;
		return ;
	}
	std::cout << "id : " << idx << std::endl;
	if (this->_amount == 0) {
		if (this->_tab != NULL) { //_tab is supposed to be null if _amount == 0, but still..
			delete [] this->_tab;
		}
		this->_tab = new IPrintable*[1];
		this->_tab[0] = obj;
		this->_amount = 1;
		return ;
	}
	IPrintable **new_tab = new IPrintable*[this->_amount + 1];
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

void	RenderMachine::addPrintable(IPrintable *obj) {
	this->addPrintable(this->_amount, obj);
}

void	RenderMachine::removePrintable(unsigned int idx) {
	if (idx >= this->_amount) {
		std::cout << "There was an error while trying to REMOVE a printable on the RenderMachine at position " << idx << ". There is only " << this->_amount << " printables in the table." << std::endl;
		return ;
	}

	IPrintable		**new_tab = new IPrintable*[this->_amount - 1];
	unsigned int	i;

	for (i = 0; i < idx; i ++) {
		new_tab[i] =this->_tab[i - 1];
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
}

IPrintable	*RenderMachine::getPrintable(unsigned int idx) {
	if (idx >= this->_amount) {
		std::cout << "There was an error while trying to GET a printable on the RenderMachine at position " << idx << ". There is only " << this->_amount << " printables in the table. Returning NULL." << std::endl;
		return NULL;
	}
	return (this->_tab[idx]);
}

unsigned int	RenderMachine::getAmount(void) const {
	return (this->_amount);
}

void					RenderMachine::describe() {
	for (unsigned int i = 0; i < this->_amount; i++) {
		std::cout << "[" << i << "] : " << this->_tab[i] << std::endl;
	}
}
