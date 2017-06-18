#ifndef HERO_CLASS_HPP
# define HERO_CLASS_HPP

#include "GameEntity.class.hpp"
#include "AMovable.class.hpp"
#include "Bullet.class.hpp"
<<<<<<< HEAD

=======
>>>>>>> 2de194423251c58f2f995d22d0d5c2d3a4d026fb
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
	// virtual void	move(int input);

	~Hero();

};

#endif
