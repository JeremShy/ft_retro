#ifndef AMOVABLE_CLASS_H
# define AMOVABLE_CLASS_H

# include <string>
# include <iostream>

class AMovable {
public:
	virtual ~AMovable(void);

private:
	int	direction[2];
};

#endif
