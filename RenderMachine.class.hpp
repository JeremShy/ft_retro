#ifndef RENDER_MACHINE_CLASS_H
# define RENDER_MACHINE_CLASS_H

# include <string>
# include <iostream>
# include "IPrintable.class.hpp"
# include "AMovable.class.hpp"
# include "IMachine.class.hpp"

class RenderMachine : public IMachine{
public:
	RenderMachine(void);
	RenderMachine(RenderMachine const & src);
	~RenderMachine(void);

	RenderMachine & operator=(RenderMachine const & rhs);

	void	renderAll(void);
	void	eraseAll(void);
	void	addPrintable(unsigned int id, IPrintable *obj);
	void	addPrintable(IPrintable *obj);
	void	removePrintable(unsigned int id);
	void	removePrintable(IPrintable *obj);
	void	removePrintable(AMovable *obj);
	IPrintable	*getPrintable(unsigned int _id);
	IPrintable  **getPrintableAll(void);

	unsigned int	getAmount(void) const;

	void	describe(void);

private:
	IPrintable		**_tab;
	unsigned int	_amount;
};

#endif
