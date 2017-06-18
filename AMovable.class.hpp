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
	bool		doesCollide(AMovable *col);

	unsigned int 	getPositionX(void) const;
	unsigned int 	getPositionY(void) const;

	float 				getRealPositionX(void) const;
	float 				getRealPositionY(void) const;

	void			setPositionX(unsigned int);
	void			setPositionY(unsigned int);

	void			setRealPositionX(float);
	void			setRealPositionY(float);

	void			setDirection(float[2]);
	void			setDirectionX(float);
	void			setDirectionY(float);


	void			move();

protected:
	float						_direction[2];

private:
	float 	_x;
	float 	_y;

};

#endif
