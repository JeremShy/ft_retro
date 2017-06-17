#include "display.hpp"

int main() {
	init_ncurse();
	while (1) {
		mvaddch(4, 4, 'c');
		char ch = getch();
		if (ch == 27) {
			endwin();
			return (0);
		}
	}
}
