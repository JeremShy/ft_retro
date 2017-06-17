#ifndef ENEMY_A_CLASS_HPP
# define ENEMY_A_CLASS_HPP

#include "Enemy.class.hpp"

class EnemyA : public Enemy
{
public:
	EnemyA();
	EnemyA(Enemy const & cpy);

	Enemy &		operator=(Enemy const & rhs);

	~EnemyA();

private:
	static const int 			c_model = 'A';
	static const unsigned int	c_health = 10;
	static const unsigned int	c_damage = 0;
	
};

#endif