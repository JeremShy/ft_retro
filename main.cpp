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
				close_ncurse();
				return 0;
				break;
			case KEY_DOWN:
				hero.setDirectionY(0.1);
				break;
			default:
				break;
		}
	}

}
