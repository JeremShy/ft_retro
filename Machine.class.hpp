#ifndef MACHINE_CLASS_H
# define MACHINE_CLASS_H

# include <string>
# include <iostream>

class Machine {
public:
	~Machine();

	virtual unsigned int	getAmount(void) const = 0;
private:
};

#endif
