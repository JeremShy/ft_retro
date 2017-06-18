#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

#include "GameEntity.class.hpp"
#include <iostream>

class Enemy : public GameEntity
{
public:
	Enemy(char model, unsigned int health, unsigned int damage);
	Enemy(Enemy const & cpy);

	Enemy &			operator=(Enemy const & rhs);

	Enemy *			clone(void);

	// virtual void	takeDamage(unsigned int damage);

	~Enemy();

};

std::ostream& operator<< (std::ostream& stream, const Enemy & enemy);

#endif
