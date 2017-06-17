#include "Enemy.class.hpp"
#include "EnemyA.class.hpp"
#include "EnemyB.class.hpp"
#include "EnemyEvents.hpp"
#include "GameEntity.class.hpp"
#include "Hero.class.hpp"
#include "Bullet.class.hpp"
#include "IPrintable.class.hpp"
#include "RenderMachine.class.hpp"
#include "display.hpp"
#include "direction.enum.hpp"
#include "AMovable.class.hpp"
#include "MotorMachine.class.hpp"
#include <curses.h>
#include <unistd.h>
#include <fstream>
#include <ctime>

int main() {
	RenderMachine rmachine;
	MotorMachine	mmachine;
	Hero hero;
	EnemyA enemy;
	EnemyB enemy2;
	time_t t1, t2;

	int ch ;

	rmachine.addPrintable(&hero);
	mmachine.addMovable(&hero);

	rmachine.addPrintable(&enemy);
	mmachine.addMovable(&enemy);
	enemy.setDirectionX(0.5);

	std::fstream file("a", std::fstream::out | std::fstream::trunc);
	file << "hei" << std::endl;

	init_ncurse();
	t1 = time(NULL);
	while (1) {
		t2 = time(NULL);
		if(t2 - t1 >= 3) {
			t1 = t2;
			Enemy *x = new EnemyA;
			rmachine.addPrintable(x);
			mmachine.addMovable(x);
			x->setDirectionX(0.2);
		}
		clear();
		mmachine.moveAll();
		rmachine.renderAll();
		refresh();
		usleep(1);
		timeout(10);
		ch = getch();
		switch (ch) {
			case 27: //Echap
				close_ncurse();
				return (0);
				break;
			case KEY_UP:
				file << "1" << std::endl;
				hero.setDirectionX(0);
				hero.setDirectionY(-0.5);
				break;
			case KEY_DOWN:
			file << "2" << std::endl;
				hero.setDirectionX(0);
				hero.setDirectionY(0.5);
				break;
			case KEY_LEFT:
				file << "3" << std::endl;
				hero.setDirectionY(0);
				hero.setDirectionX(-0.5);
				break;
			case KEY_RIGHT:
				file << "4" << std::endl;
				hero.setDirectionY(0);
				hero.setDirectionX(0.5);
				break;
			default:
				hero.setDirectionY(0);
				hero.setDirectionX(0);
				break;
		}
	}
}
