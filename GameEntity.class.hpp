#ifndef GAME_ENTITY_HPP
# define GAME_ENTITY_HPP

# include "Direction.enum.hpp"

# define UP_ARROW 1
# define DOWN_ARROW 2
# define LEFT_ARROW 3
# define RIGHT_ARROW 4

class GameEntity
{
public:
	GameEntity(char const model, unsigned int x, unsigned int y, unsigned int health, unsigned int damage);
	GameEntity(GameEntity const & cpy);

	GameEntity & 	operator=(GameEntity const &);

	virtual GameEntity *	clone();

	void					display(void);
	void					erase(void);
	virtual void			takeDamage(unsigned int);
	// virtual void			move(int input);

	char			getModel(void) const;
	int 			getPositionX(void) const;
	int 			getPositionY(void) const;
	unsigned int 	getHealth(void) const;
	unsigned int 	getDamage(void) const;

	void			setModel(char model);
	void 			setPositionX(int x) const;
	void 			setPositionY(int y) const;
	void		 	setHealth(unsigned int health) const;
	void		 	setDamage(unsigned int damage) const;

	virtual ~GameEntity();

protected:
	GameEntity();
	char 			_model;
	int 			_x;
	int 			_y;
	unsigned int 	_health;
	unsigned int 	_damage;

};

#endif
