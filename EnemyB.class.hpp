#ifndef ENEMY_B_CLBSS_HPP
# define ENEMY_B_CLBSS_HPP

#include "Enemy.class.hpp"

class EnemyB : public Enemy
{
public:
	EnemyB();
	EnemyB(Enemy const & cpy);

	Enemy &		operator=(Enemy const & rhs);

	~EnemyB();

};

#endif