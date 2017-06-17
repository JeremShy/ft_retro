#ifndef DISPLAY_H
#define DISPLAY_H

#include <ncurses.h>
#include "IPrintable.class.hpp"

void	print_ip(IPrintable *target);
void	erase_ip(IPrintable *target);
void	init_ncurse(void);
void	close_ncurse(void);

#endif
