#ifndef BULLET_CLASS_HPP
# define BULLET_CLASS_HPP

# include "IPrintable.class.hpp"

class Bullet : public IPrintable
{
public:
	Bullet(int x, int y, int damage);
	Bullet(Bullet const & cpy);

	Bullet &		operator=(Bullet const & rhs);

	void			move(void) const;

	int 			getPositionX(void) const;
	int 			getPositionY(void) const;
	int 			getDamage(void) const;

	void			setPositionX(int x);
	void			setPositionY(int y);
	void			setDamage(int damage);

	virtual Bullet *clone(void);
	virtual void	display(void);

	~Bullet();

private:
	int 			_x;
	int 			_y;
	int const		_damage;
	
};

#endif