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

	~Hero();

private:
	static const int			c_model = 'H'; //You might change that but anyway
	static const unsigned int	c_health = 100;
	static const unsigned int	c_damage = 20;
	
};

#endif