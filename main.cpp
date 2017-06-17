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


int main() {
	RenderMachine rmachine;
	MotorMachine	mmachine;
	Hero hero;
	int ch ;

	rmachine.addPrintable(&hero);
	mmachine.addMovable(&hero);
	// rmachine.describe();
//
	init_ncurse();
	timeout(20);
	while (1) {
		rmachine.eraseAll();
		mmachine.moveAll();
		rmachine.renderAll();
		refresh();
		ch = getch();
		switch (ch){
			case KEY_UP:
				hero.setDirectionY(-0.5);
				break;
			case KEY_DOWN:
				hero.setDirectionY(0.5);
				break;
			case KEY_LEFT:
				hero.setDirectionX(-0.5);
				break;
			case KEY_RIGHT:
				hero.setDirectionX(0.5);
				break;
			default:
				hero.setDirectionY(0);
				hero.setDirectionX(0);
				break;
		}
	}

}
