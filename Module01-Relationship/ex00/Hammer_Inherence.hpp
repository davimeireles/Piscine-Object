#pragma once

#include "Tool_Inherence.hpp"

class Hammer : public Tool
{
public:
	Hammer(void);
	~Hammer(void);

	void use(void);
};
