#include "display.hpp"

void	print_ge(GameEntity *target) {
	mvaddch(target->getPositionY(), target->getPositionX(), target->getModel());
}

void	init_ncurse(void) {
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
}

void	close_ncurse(void) {
	endwin();
}
