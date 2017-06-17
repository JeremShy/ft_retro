#ifndef AMOVABLE_CLASS_H
# define AMOVABLE_CLASS_H

# include <string>
# include <iostream>

class Movable {
public:
	Movable(void);
	Movable(int x, int y);
	Movable(Movable const & src);
	~Movable(void);

	Movable & operator=(Movable const & rhs);

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
