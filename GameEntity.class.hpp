#ifndef GAME_ENTITY_HPP
# define GAME_ENTITY_HPP

# include "IPrintable.class.hpp"

# define UP_ARROW 1
# define DOWN_ARROW 2
# define LEFT_ARROW 3
# define RIGHT_ARROW 4

class GameEntity : public IPrintable
{
public:
	GameEntity(char const model, unsigned int x = 0, unsigned int y = 0, unsigned int health = 0, unsigned int damage = 0);
	GameEntity(GameEntity const & cpy);

	GameEntity & 	operator=(GameEntity const &);

	virtual GameEntity *	clone();

	void					display(void);
	virtual void			attack(void);
	virtual void			takeDamage(unsigned int);
	virtual void			move(int input);

	char			getModel(void) const;
	unsigned int 	getHealth(void) const;
	unsigned int 	getDamage(void) const;
	unsigned int 	getPositionX(void) const;
	unsigned int 	getPositionY(void) const;

	void			setModel(char model);
	void			setHealth(unsigned int);
	void			setDamage(unsigned int);
	void			setPositionX(unsigned int);
	void			setPositionY(unsigned int);

	virtual ~GameEntity();

private:
	GameEntity();
	char 			_model;
	unsigned int 	_x;
	unsigned int 	_y;
	unsigned int 	_health;
	unsigned int 	_damage;

};

#endif
