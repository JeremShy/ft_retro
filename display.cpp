#include "display.hpp"

void	print_ip(GameEntity *target) {
	target->display();
}

void	erase_ip(GameEntity *target) {
	target->erase();
}

void	init_ncurse(void) {
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, TRUE);
}

void	close_ncurse(void) {
	endwin();
}
