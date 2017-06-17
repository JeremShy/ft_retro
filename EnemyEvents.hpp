#ifndef ENEMY_EVENTS_HPP
# define ENEMY_EVENTS_HPP

#include "Enemy.class.hpp"
#include "EnemyA.class.hpp"
#include "EnemyB.class.hpp"

Enemy*			spawnRand(void);
Enemy**			spawnHorde(int level);

#endif
