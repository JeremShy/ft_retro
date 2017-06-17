#ifndef GAME_ENTITY_HPP
# define GAME_ENTITY_HPP

# include "IPrintable.class.hpp"

class GameEntity : public IPrintable
{
public:
	GameEntity(char const model, unsigned int x, unsigned int y, unsigned int health, unsigned int damage);
	GameEntity(GameEntity const & cpy);

	GameEntity & 	operator=(GameEntity const &);

	virtual GameEntity *	clone();

	void					display(void);
	virtual void			attack(void);
	virtual void			takeDamage(unsigned int);

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
