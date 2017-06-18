#ifndef GAME_ENTITY_HPP
# define GAME_ENTITY_HPP

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
	virtual void					move();
	bool							escapedBoundaries(void);
	bool					doesCollide(GameEntity *col);
	// virtual void			move(int input);

	char			getModel(void) const;
	unsigned int	getPositionX(void) const;
	unsigned int	getPositionY(void) const;
	float 			getRealPositionX(void) const;
	float 			getRealPositionY(void) const;

	void			setPositionX(unsigned int);
	void			setPositionY(unsigned int);

	void			setRealPositionX(float);
	void			setRealPositionY(float);

	void			setDirection(float[2]);
	void			setDirectionX(float);
	void			setDirectionY(float);
	unsigned int 	getHealth(void) const;
	unsigned int 	getDamage(void) const;

	void			setModel(char model);
	void		 	setHealth(unsigned int health);
	void		 	setDamage(unsigned int damage);

	virtual ~GameEntity();

protected:
	GameEntity();
	float		 	_x;
	float		 	_y;
	unsigned int 	_health;
	unsigned int 	_damage;
	char 			_model;
	float			_direction[2];

};

#endif
