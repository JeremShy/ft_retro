#include "EnemyEvents.hpp"
#include <sys/ioctl.h>
#include <fstream>
#include "display.hpp"

int				enemiesPerLevel[5] = {10, 25, 60, 80, 100};

Enemy*			spawnRand(void){

	static std::fstream log("log", std::fstream::out | std::fstream::trunc); //Simple fichier permettant de faire des debugs simples sans avoir à passer par la console. Faudra virer ça au rendu :).

	int		random = rand() % 2;
	Enemy	*ret;

	if (random == 0)
		ret = new EnemyA;
	else
		ret = new EnemyB;
	struct winsize size;
	if (ioctl(0, TIOCGWINSZ, (char *) &size) < 0)
	{
		close_ncurse();
		std::cout << "error with ioctl" << std::endl;
		exit(EXIT_FAILURE);
	}
	int	y = rand() % size.ws_row;
	int x = size.ws_col - rand() % 30;
	log << "Spawning enenmy at "<< x << " - " << y << std::endl;
	ret->setPositionX(x);
	ret->setPositionY(y);
	ret->setDirectionX(-1.0 * (((rand() % 4) + 1)) / 4);
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
