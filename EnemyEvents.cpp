#include "EnemyEvents.hpp"

int				enemiesPerLevel[5] = [10, 25, 60, 80, 100];

Enemy*			spawnRand(void){
	int		rand = arc4random() % 2;

	if (rand == 0)
		return new EnemyA;
	else
		return new EnemyB;
}

Enemy**			spawnHorde(int level){
	if (level <= 4){
		
		int			enemiesCount = enemiesPerLevel[level];
		Enemy*		horde[enemiesCount];

		while(--enemiesCount >= 0){
			horde[enemiesCount] = spawnRand();
		}
		return horde;
	}
	
}