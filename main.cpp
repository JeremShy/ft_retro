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
	machine.renderAll();
	while (1) {
		refresh();
		ch = getch();
		switch (ch){
			case KEY_UP:
				close_ncurse();
				return 0;
				break;
			default:
			break;
		}
	}

}
