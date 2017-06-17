#ifndef IPRINTABLE_CLASS_H
# define IPRINTABLE_CLASS_H

# include <string>
# include <iostream>

class IPrintable {
public:
	virtual							~IPrintable(void);
	virtual void				display() = 0;
	virtual IPrintable	*clone();
};

#endif
