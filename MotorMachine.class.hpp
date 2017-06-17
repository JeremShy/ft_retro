#ifndef MOTOR_MACHINE_CLASS_H
# define MOTOR_MACHINE_CLASS_H

# include <string>
# include <iostream>
# include "Movable.class.hpp"

class MotorMachine {
public:
	MotorMachine(void);
	MotorMachine(MotorMachine const & src);
	~MotorMachine(void);

	MotorMachine & operator=(MotorMachine const & rhs);

	void	moveAll(void);
	void	addMovable(unsigned int id, Movable *obj);
	void	addMovable(Movable *obj);
	void	removeMovable(unsigned int id);
	Movable	*getMovable(unsigned int _id);

	unsigned int	getAmount(void) const;

	void	describe(void);

private:
	Movable		**_tab;
	unsigned int	_amount;
};

#endif
