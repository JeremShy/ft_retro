#include "display.hpp"
#include "Timer.class.hpp"
#include <sys/ioctl.h>
#include <iostream>
#include <sstream>

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

int	get_size_x(void) {
	struct winsize size;
	if (ioctl(0, TIOCGWINSZ, (char *) &size) < 0)
	{
		close_ncurse();
		std::cout << "error with ioctl" << std::endl;
		exit(EXIT_FAILURE);
	}
	return size.ws_col;
}

int	get_size_y(void) {
	struct winsize size;
	if (ioctl(0, TIOCGWINSZ, (char *) &size) < 0)
	{
		close_ncurse();
		std::cout << "error with ioctl" << std::endl;
		exit(EXIT_FAILURE);
	}
	return (size.ws_row - 5);
}

void	print_interface(Hero *hero)
{
	static Timer t;
	static int i = 0;

	if (i == 0)
	{
		t.start();
		i = 1;
	}
	int sy = get_size_y();
	std::string str(get_size_x(), '/');
	for (unsigned int i = 0; i < str.length(); i++)
	{
		mvaddch(sy, i, str[i]);
	}
	std::stringstream buf;
	buf << "x : " << hero->getPositionX() << " - y : " << hero->getPositionY();
	buf << " hp : " << hero->getHealth() << " timer : " << t.get_millis_time();
	str = buf.str();
	for (unsigned int i = 0; i < str.length(); i++)
	{
		mvaddch(sy + 1, i, str[i]);
	}
}