#include "Enemy.class.hpp"
#include "EnemyA.class.hpp"
#include "EnemyB.class.hpp"
#include "EnemyEvents.hpp"
#include "GameEntity.class.hpp"
#include "Hero.class.hpp"
#include "IPrintable.class.hpp"
#include "RenderMachine.class.hpp"
#include "display.hpp"


int main() {
	RenderMachine machine;
	machine.addPrintable(spawnRand());
	machine.addPrintable(spawnRand());
	machine.addPrintable(spawnRand());
	machine.addPrintable(spawnRand());
	machine.addPrintable(spawnRand());
	machine.describe();

	init_ncurse();
	machine.renderAll();
	while (1) {
		char ch = getch();
		if (ch == 27) {
			endwin();
			return (0);
		}
	}
}
