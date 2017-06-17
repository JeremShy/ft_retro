#include "RenderMachine.class.hpp"

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
		this->_tab[i]->display();
	}
}
