#ifndef BULLET_CLASS_HPP
# define BULLET_CLASS_HPP

# include "IPrintable.class.hpp"
# include "GameEntity.class.hpp"

class Bullet : public IPrintable
{
public:
	Bullet(int x, int y, int damage, GameEntity * shooter);
	Bullet(Bullet const & cpy);

	Bullet &		operator=(Bullet const & rhs);

	void			move(void);

	int 			getPositionX(void) const;
	int 			getPositionY(void) const;
	int 			getDamage(void) const;
	GameEntity *	getShooter(void) const;

	void			setPositionX(int x);
	void			setPositionY(int y);
	void			setDamage(int damage);
	void			setShooter(GameEntity * shooter);

	virtual Bullet *clone(void);
	virtual void	display(void);
	virtual void	erase(void);

	~Bullet();

private:
	int 			_x;
	int 			_y;
	int 			_damage;
	GameEntity *	_shooter;

};

#endif
