#include <iostream>
#include <fstream>
#include "GameMachine.class.hpp"


GameMachine::GameMachine(void)
{
	for (int i = 0; i < 5000; i++)
	{
		_tab[i] = NULL;
	}
}

GameMachine::GameMachine(GameMachine const & src)
{
	for (int i = 0; i < 5000; i++)
	{
		_tab[i] = NULL;
	}
	for (unsigned int i = 0; i < 5000; i++)
	{
		if (this->_tab[i])
			this->_tab[i] = src._tab[i]->clone();
		else
			this->_tab[i] = NULL;
	}
}

GameMachine::~GameMachine(void)
{
}

GameMachine & GameMachine::operator=(GameMachine const & rhs)
{
	for (int i = 0; i < 5000; i++)
	{
		_tab[i] = NULL;
	}
	for (unsigned int i = 0; i < 5000; i++)
	{
		if (this->_tab[i])
			this->_tab[i] = rhs._tab[i]->clone();
		else
			this->_tab[i] = NULL;
	}
	return (*this);
}

void	GameMachine::renderAll(void)
{
	for (unsigned int i = 0; i < 5000; i++)
	{
		if (this->_tab[i])
			(this->_tab[i])->display();
	}
}

void	GameMachine::eraseAll(void)
{
	for (unsigned int i = 0; i < 5000; i++)
	{
		// log << "i : " << i << std::endl;
		if (this->_tab[i])
			(this->_tab[i])->erase();
	}
}

void	GameMachine::moveAll()
{
	std::fstream log("log", std::fstream::out | std::fstream::app);
	for (unsigned int i = 0; i < 5000; i++)
	{
		if (this->_tab[i])
		{
			(this->_tab[i])->move();
			if ((this->_tab[i])->escapedBoundaries())
			{
				log << "Out of bonds : " << _tab[i] << std::endl;
				delete this->_tab[i];
				this->_tab[i] = NULL;
				continue;
			}
			else
			{
				for (unsigned int y = 0; y < 5000; y++)
				{
					if (this->_tab[y])
					{
						if (y != i)
						{
							if ((this->_tab[i])->doesCollide(this->_tab[y]))
							{
								this->_tab[i]->takeDamage(this->_tab[y]->getDamage());
								this->_tab[y]->takeDamage(this->_tab[i]->getDamage());

								if (this->_tab[i]->getHealth() == 0)
								{
									log << "trying to remove item at " << this->_tab[i] << ". (first if)" << std::endl;
									delete this->_tab[i];
									this->_tab[i] = NULL;
								}

								if (this->_tab[y]->getHealth() == 0)
								{
									log << "trying to remove item at " << this->_tab[y] << ". (second if)" << std::endl;
									delete this->_tab[y];
									this->_tab[y] = NULL;
								}
							}
						}
					}
				}
			}
		}
	}
	log.close();
}

void	GameMachine::moveAllExcept(GameEntity *obj)
{
	std::fstream log("log", std::fstream::out | std::fstream::app);
	for (unsigned int i = 0; i < 5000; i++)
	{
		if (this->_tab[i] && this->_tab[i] != obj)
		{
			(this->_tab[i])->move();
			if ((this->_tab[i])->escapedBoundaries())
			{
				log << "Out of bonds : " << _tab[i] << std::endl;
				delete this->_tab[i];
				this->_tab[i] = NULL;
				continue;
			}
			else
			{
				for (unsigned int y = 0; y < 5000; y++)
				{
					if (this->_tab[y] && this->_tab[i])
					{
						if (y != i)
						{
							if ((this->_tab[i])->doesCollide(this->_tab[y]))
							{
								this->_tab[i]->takeDamage(this->_tab[y]->getDamage());
								this->_tab[y]->takeDamage(this->_tab[i]->getDamage());

								if (this->_tab[i]->getHealth() == 0)
								{
									log << "trying to remove item at " << this->_tab[i] << ". (first if)" << std::endl;
									delete this->_tab[i];
									this->_tab[i] = NULL;
								}

								if (this->_tab[y]->getHealth() == 0)
								{
									log << "trying to remove item at " << this->_tab[y] << ". (second if)" << std::endl;
									delete this->_tab[y];
									this->_tab[y] = NULL;
								}
							}
						}
					}
				}
			}
		}
	}
	log.close();
}


void	GameMachine::addGE(GameEntity *obj)
{
	std::fstream log("log", std::fstream::out | std::fstream::app);
	log << "Trying to add a Game Entity directly [" << obj << "] at the end of the pile" << std::endl;

	unsigned int		i;

	for (i = 0; i < 5000; i++)
	{
		if (!this->_tab[i])
		{
			this->_tab[i] = obj;
			return;
		}
	}
	log.close();
}

void	GameMachine::removeGE(GameEntity *obj)
{
	std::fstream log("log", std::fstream::out | std::fstream::app);
	for (unsigned int i = 0; i < 5000; i++)
	{
		if (this->_tab[i] == obj)
		{
			this->_tab[i] = NULL;
			return ;
		}
	}
	log << "There was an error while trying to REMOVE a Game Entity." << std::endl;
	log.close();
}

void					GameMachine::describe()
{
	// std::fstream log("log", std::fstream::out | std::fstream::app);
	// log << "Describing printables - amount : " << this->_amount << std::endl;
	// for (unsigned int i = 0; i < this->_amount; i++)
	// {
	// 	log << "[" << i << "] : " << this->_tab[i] << std::endl;
	// }
	// log.close();
}
