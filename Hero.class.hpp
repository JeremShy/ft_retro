#ifndef HERO_CLASS_HPP
# define HERO_CLASS_HPP

#include "GameEntity.class.hpp"
#include "Bullet.class.hpp"

class Hero : public GameEntity
{
public:
	Hero();
	Hero(Hero const & cpy);

	Hero &				operator=(Hero const & rhs);

	Hero *				clone(void);

	virtual void		attack(void);
	Bullet					*shoot(void);
	virtual void		takeDamage(unsigned int damage);

	void				move(void);

	// virtual void	move(int input);

	~Hero();

};

#endif
