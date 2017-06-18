#include "EnemyEvents.hpp"
#include <sys/ioctl.h>
#include <fstream>
#include "display.hpp"

int				enemiesPerLevel[5] = {10, 25, 60, 80, 100};

Enemy*			spawnRand(void){

	static std::fstream log("log", std::fstream::out | std::fstream::app); //Simple fichier permettant de faire des debugs simples sans avoir à passer par la console. Faudra virer ça au rendu :).

	int		random = rand() % 2;
	Enemy	*ret;

	if (random == 0)
		ret = new EnemyA;
	else
		ret = new EnemyB;
	int	y = rand() % get_size_y();
	int x = get_size_x() - rand() % 30;
	ret->setPositionX(x);
	ret->setPositionY(y);
	double velocity = ((rand() % 3) + 14) / 100.0;
	velocity *= -1.0;
	// double velocity = -.15;
	log << "Spawning enenmy at "<< x << " - " << y << " with velocity : " << velocity << ", and with address: " << ret << std::endl;
	ret->setDirectionX(velocity);
	return (ret);
}

Enemy**			spawnHorde(int level){
	if (level <= 4){
		int			enemiesCount = enemiesPerLevel[level];
		Enemy**		horde = new Enemy*[enemiesCount];

		while(--enemiesCount >= 0){
			horde[enemiesCount] = spawnRand();
		}
		return horde;
	}
	std::cout << "Error: You tried to create a horde of level : " << level << ". Returning NULL." << std::endl;
	return (NULL);
}
