#ifndef IMACHINE_CLASS_H
# define IMACHINE_CLASS_H

# include <string>
# include <iostream>

class IMachine {
public:
	~IMachine();

	virtual unsigned int	getAmount(void) const = 0;
private:
};

#endif
