#ifndef ENEMY_B_CLBSS_HPP
# define ENEMY_B_CLBSS_HPP

#include "Enemy.class.hpp"
#include <iostream>

class EnemyB : public Enemy
{
public:
	EnemyB();
	EnemyB(EnemyB const & cpy);

	EnemyB &		operator=(EnemyB const & rhs);

	~EnemyB();

};

#endif
