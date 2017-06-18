#ifndef AMOVABLE_CLASS_H
# define AMOVABLE_CLASS_H

# include <string>
# include <iostream>

class AMovable {
public:
	AMovable(void);
	AMovable(int x, int y, unsigned int health, unsigned int damage);
	AMovable(AMovable const & src);
	virtual ~AMovable(void);

	AMovable & operator=(AMovable const & rhs);
	virtual		AMovable *clone() = 0;
	bool		doesCollide(AMovable *col);

	unsigned int 	getPositionX(void) const;
	unsigned int 	getPositionY(void) const;

	unsigned int	getHealth(void) const;
	unsigned int	getDamage(void) const;

	float 			getRealPositionX(void) const;
	float 			getRealPositionY(void) const;

	void			setPositionX(unsigned int);
	void			setPositionY(unsigned int);

	void			setRealPositionX(float);
	void			setRealPositionY(float);

	void			setDirection(float[2]);
	void			setDirectionX(float);
	void			setDirectionY(float);

	void			setHealth(unsigned int);
	void			setDamage(unsigned int);

	virtual void	takeDamage(unsigned int damage) = 0;


	//virtual void			takeDamage(unsigned int amount);
	//virtual unsigned int	getDamage(void) const;

	void			move();

protected:
	float						_direction[2];

private:
	float 	_x;
	float 	_y;
	unsigned int		_health;
	unsigned int		_damage;

};

#endif
