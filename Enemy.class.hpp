#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

#include "GameEntity.class.hpp"

class Enemy : public GameEntity
{
public:
	Enemy(char model, unsigned int health, unsigned int damage);
	Enemy(Enemy const & cpy);

	Enemy &			operator=(Enemy const & rhs);

	Enemy *			clone(void);

	virtual void	attack(void);
	virtual void	takeDamage(unsigned int damage);

	~Enemy();
	
};

#endif