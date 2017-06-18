#ifndef GAME_MACHINE_CLASS_H
# define GAME_MACHINE_CLASS_H

# include <string>
# include <iostream>
# include "GameEntity.class.hpp"

class GameMachine {
public:
	GameMachine(void);
	GameMachine(GameMachine const & src);
	~GameMachine(void);

	GameMachine & operator=(GameMachine const & rhs);

	void	renderAll(void);
	void	eraseAll(void);

	void	moveAll();
	void	moveAllExcept(GameEntity *obj);

	void	addGE(GameEntity *obj);
	void	removeGE(GameEntity *obj);

	unsigned int	getAmount(void) const;

	void	describe(void);

private:
	GameEntity		*_tab[5000];
	// unsigned int	_amount;
};

#endif
