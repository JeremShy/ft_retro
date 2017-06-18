#ifndef DISPLAY_H
#define DISPLAY_H

#include <ncurses.h>
#include "GameEntity.class.hpp"
#include "Hero.class.hpp"

void	print_ip(GameEntity *target);
void	erase_ip(GameEntity *target);
void	init_ncurse(void);
void	close_ncurse(void);
int		get_size_x(void);
int		get_size_y(void);
void	print_interface(Hero *hero);

#endif
