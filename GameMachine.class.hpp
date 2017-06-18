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

	void	addGE(unsigned int id, GameEntity *obj);
	void	addGE(GameEntity *obj);
	void	removeGE(unsigned int id);
	void	removeGE(GameEntity *obj);

	GameEntity	*getGE(unsigned int _id);
	GameEntity  **getGEAll(void);

	unsigned int	getAmount(void) const;

	void	describe(void);

private:
	GameEntity		**_tab;
	unsigned int	_amount;
};

#endif
