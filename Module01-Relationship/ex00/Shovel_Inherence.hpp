#pragma once

#include "Tool_Inherence.hpp"

class Shovel : public Tool
{
public:
	Shovel(void);
	~Shovel(void);

	void use(void);
};
