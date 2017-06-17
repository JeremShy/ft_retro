#include "display.hpp"

void	print_ip(IPrintable *target) {
	target->display();
}

void	erase_ip(IPrintable *target) {
	target->erase();
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
