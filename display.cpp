#include "display.hpp"

void	print_ge(GameEntity *target) {
	mvaddch(target->getPositionX(), target->getPositionY(), target->getModel());
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
