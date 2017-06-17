#ifndef ENEMY_EVENTS_CLASS_HPP
# define ENEMY_EVENTS_CLASS_HPP

#include "Enemy.class.hpp"
#include "EnemyA.class.hpp"
#include "EnemyB.class.hpp"

class EnemyEvents
{
public:
	EnemyEvents(int level);
	EnemyEvents(EnemyEvents const & cpy);

	EnemyEvents & 		operator=(EnemyEvents const & rhs);

	Enemy *				spawnRand(void);
	EnemyEvents &		spawnHorde(int);

	~EnemyEvents();

private:
	int					count;
	Enemy**				_horde;
	
};

std::ostream &			operator<<(std::ostream &o, EnemyEvents event);

#endif