#ifndef IPRINTABLE_CLASS_H
# define IPRINTABLE_CLASS_H

# include <string>
# include <iostream>

class IPrintable {
public:
	virtual							~IPrintable(void);

	virtual void				display() = 0;
	virtual void				erase() = 0;
	virtual IPrintable	*clone() = 0;

};

#endif
