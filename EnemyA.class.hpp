#ifndef ENEMY_A_CLASS_HPP
# define ENEMY_A_CLASS_HPP

#include "Enemy.class.hpp"
#include <iostream>

class EnemyA : public Enemy
{
public:
	EnemyA();
	EnemyA(EnemyA const & cpy);

	EnemyA &		operator=(EnemyA const & rhs);

	~EnemyA();

};

std::ostream& operator<< (std::ostream& stream, const EnemyA & enemy);

#endif
