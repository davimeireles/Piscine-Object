#include "Tool_Inherence.hpp"

Tool::Tool(void) : numberOfUses(0)
{
	std::cout << "Tool Constructor called." << std::endl;
}

Tool::~Tool(void)
{
	std::cout << "Tool Destructor called." << std::endl;
}

int Tool::getNumberOfUses(void) const
{
	return this->numberOfUses;
}
