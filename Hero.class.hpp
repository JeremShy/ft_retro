#ifndef HERO_CLASS_HPP
# define HERO_CLASS_HPP

class Hero : public GameEntity
{
public:
	Hero();
	Hero(Hero const & cpy);

	Hero &			operator=(Hero const & rhs);

	Hero *			clone(void);

	virtual void	attack(void);
	virtual void	takeDamage(unsigned int damage);

	~Hero();

private:
	char const			c_model = 'H'; //You might change that but anyway
	unsigned int const	c_health = 100;
	unsigned int const	c_damage = 20;
	
};

#endif