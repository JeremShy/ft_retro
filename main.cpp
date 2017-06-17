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
#include <curses.h>


int main() {
	RenderMachine machine;
	Hero hero;
	int ch ;

	machine.addPrintable(&hero);
	machine.describe();

	init_ncurse();
	timeout(20);
	while (1) {
		machine.eraseAll();
		hero.move();
		machine.renderAll();
		refresh();
		ch = getch();
		switch (ch){
			case KEY_UP:
				close_ncurse();
				return 0;
				break;
			case KEY_DOWN:
				hero.setDirectionY(1);
				break;
			default:
				break;
		}
	}

}
