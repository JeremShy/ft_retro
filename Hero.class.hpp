#ifndef HERO_CLASS_HPP
# define HERO_CLASS_HPP

#include "GameEntity.class.hpp"

class Hero : public GameEntity
{
public:
	Hero();
	Hero(Hero const & cpy);

	Hero &			operator=(Hero const & rhs);

	Hero *			clone(void);

	virtual void	attack(void);
	virtual void	takeDamage(unsigned int damage);
	virtual void	move(int input);

	~Hero();
	
};

#endif