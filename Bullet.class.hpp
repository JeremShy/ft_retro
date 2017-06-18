#ifndef BULLET_CLASS_HPP
# define BULLET_CLASS_HPP

# include "GameEntity.class.hpp"

class Bullet : public GameEntity
{
public:
	Bullet(char model, int x, int y, unsigned int health, unsigned int damage);
	Bullet(Bullet const & cpy);

	Bullet &		operator=(Bullet const & rhs);

	virtual Bullet *clone(void);
	virtual void	takeDamage(unsigned int);

	~Bullet();

};

#endif
