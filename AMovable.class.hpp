#ifndef AMOVABLE_CLASS_H
# define AMOVABLE_CLASS_H

# include <string>
# include <iostream>

class AMovable {
public:
	AMovable(void);
	AMovable(int x, int y);
	AMovable(AMovable const & src);
	~AMovable(void);

	AMovable & operator=(AMovable const & rhs);
	virtual		AMovable *clone() = 0;

	unsigned int 	getPositionX(void) const;
	unsigned int 	getPositionY(void) const;

	void			setPositionX(unsigned int);
	void			setPositionY(unsigned int);
	void			setDirection(unsigned int[2]);
	void			setDirectionX(unsigned int);
	void			setDirectionY(unsigned int);


	void			move();

protected:
	int						_direction[2];
	unsigned int 	_x;
	unsigned int 	_y;
};

#endif
