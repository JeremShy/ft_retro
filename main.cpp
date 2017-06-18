#include "Enemy.class.hpp"
#include "EnemyA.class.hpp"
#include "EnemyB.class.hpp"
#include "EnemyEvents.hpp"
#include "GameEntity.class.hpp"
#include "Hero.class.hpp"
#include "Bullet.class.hpp"
#include "display.hpp"
#include "Timer.class.hpp"
#include "GameMachine.class.hpp"
#include <curses.h>
#include <unistd.h>
#include <fstream>
#include <ctime>

int main() {

	std::fstream loga("log", std::fstream::out | std::fstream::trunc);
	loga << std::endl;
	loga.close();
	std::fstream log("log", std::fstream::out | std::fstream::app);
	init_ncurse();

	GameMachine		machine;
	Hero *hero = new Hero();
	hero->setDirectionX(0);
	hero->setDirectionY(0);
	Enemy *enemy;
	// Enemy *enemy2 = new EnemyB();
	Timer t1, t2; /*Timer est une classe qui permet de créer un chronometre. On le démarre avec start() et on peu ensuite récupérer le temps écoulé depuis son démarrage avec Timer::getDiffAsMillis(). Y a aussi la methode restart() qui fait
									exactement la même chose que la méthode start(), mais je trouvais start plus claire. Ici, on crée un timer par intervalle de temps qu'on souhaite tester. */
	int ch ;

	log << "Adding hero : " << hero << std::endl;
	machine.addGE(hero);

	log << "starting program !" << std::endl;
	// log << "Adding enemy to both machines " << enemy << std::endl;

	t1.start();
	t2.start();
	while (1) {
		/*
			Il suffit de créer des timers comme suit pour les evenements arrivant toutes les quelques secondes. ici par exemple, tous les ennemis vont bouger 5 fois par secondes, et un nouvel ennemi popera toutes les trois secondes.
			ceci sans interrompre les actions du joueur.
		*/
		if(t1.getDiffAsMillis() >= 1500) {
			t1.restart();
			enemy = spawnRand();
			log << "Adding enemy to both machines " << enemy << std::endl;
			machine.addGE(enemy);
		}
		if(t2.getDiffAsMillis() >= 1000 / 200) {
			t2.restart();
			machine.moveAllExcept(hero);
		}
		clear();
		hero->move();
		machine.renderAll();
		print_interface(hero);
		refresh();
		timeout(0); //Permet de rendre l'appel à getch() non bloquant.
		ch = getch();
		switch (ch) {
			case 27: //Echap
				close_ncurse();
				return (0);
				break;
			case KEY_UP:
				hero->setDirectionX(0);
				hero->setDirectionY(-1);
				break;
			case KEY_DOWN:
				hero->setDirectionX(0);
				hero->setDirectionY(1);
				break;
			case KEY_LEFT:
				hero->setDirectionY(0);
				hero->setDirectionX(-1);
				break;
			case KEY_RIGHT:
				hero->setDirectionY(0);
				hero->setDirectionX(1);
				break;
			case ' ':
				machine.addGE(hero->shoot());
				break;
			default:
				hero->setDirectionY(0);
				hero->setDirectionX(0);
				break;
		}
	}
}
