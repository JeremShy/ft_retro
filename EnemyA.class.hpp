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

};

#endif