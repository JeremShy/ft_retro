#ifndef DISPLAY_H
#define DISPLAY_H

#include <ncurses.h>
#include "GameEntity.class.hpp"

void	print_ge(GameEntity *target);
void	init_ncurse(void);
void	close_ncurse(void);	

#endif
