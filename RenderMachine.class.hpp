#ifndef RENDER_MACHINE_CLASS_H
# define RENDER_MACHINE_CLASS_H

# include <string>
# include <iostream>
# include "IPrintable.class.hpp"

class RenderMachine {
public:
	RenderMachine(void);
	RenderMachine(RenderMachine const & src);
	~RenderMachine(void);

	RenderMachine & operator=(RenderMachine const & rhs);

	void	renderAll(void);
	void	addPrintable(unsigned int id, IPrintable *obj);
	void	addPrintable(IPrintable *obj);
	void	removePrintable(unsigned int id);
	IPrintable	*getPrintable(unsigned int _id);

	unsigned int	getAmount(void) const;
private:
	IPrintable		**_tab;
	unsigned int	_amount;
};

#endif
