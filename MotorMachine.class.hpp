#ifndef MOTOR_MACHINE_CLASS_H
# define MOTOR_MACHINE_CLASS_H

# include <string>
# include <iostream>
# include "AMovable.class.hpp"
# include "Machine.class.hpp"

class MotorMachine : public Machine {
public:
	MotorMachine(void);
	MotorMachine(MotorMachine const & src);
	~MotorMachine(void);

	MotorMachine & operator=(MotorMachine const & rhs);

	void	moveAll(void);
	void	addMovable(unsigned int id, AMovable *obj);
	void	addMovable(AMovable *obj);
	void	removeMovable(unsigned int id);
	void	removeMovable(AMovable *obj);
	AMovable	*getMovable(unsigned int _id);

	unsigned int	getAmount(void) const;

	void	describe(void);

private:
	AMovable		**_tab;
	unsigned int	_amount;
};

#endif
