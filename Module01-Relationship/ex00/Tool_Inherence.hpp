#pragma once

#include <iostream>

class Tool
{
protected:
	int numberOfUses;

public:
	Tool(void);
	virtual ~Tool(void);

	virtual void use(void) = 0;
	int getNumberOfUses(void) const;
};
