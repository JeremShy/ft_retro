#ifndef MOTOR_MACHINE_CLASS_H
# define MOTOR_MACHINE_CLASS_H

# include <string>
# include <iostream>
# include "AMovable.class.hpp"
# include "IMachine.class.hpp"
# include "GameEntity.class.hpp"

class MotorMachine : public IMachine {
public:
	MotorMachine(void);
	MotorMachine(MotorMachine const & src);
	~MotorMachine(void);

	MotorMachine & operator=(MotorMachine const & rhs);

	void	moveAll(void);
	void	moveAllExcept(AMovable *obj);
	void	addMovable(unsigned int id, AMovable *obj);
	void	addMovable(AMovable *obj);
	void	removeMovable(unsigned int id);
	void	removeMovable(AMovable *obj);
	AMovable	*getMovable(unsigned int _id);
	void	collide(RenderMachine &rmachine, GameEntity **props, int amount);

	unsigned int	getAmount(void) const;

	void	describe(void);

private:
	AMovable		**_tab;
	unsigned int	_amount;
};

#endif
