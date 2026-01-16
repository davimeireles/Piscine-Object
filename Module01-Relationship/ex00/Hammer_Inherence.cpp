#include "Hammer_Inherence.hpp"

Hammer::Hammer(void) : Tool()
{
	this->numberOfUses = 3;
	std::cout << "Hammer Constructor called with " << this->numberOfUses << " uses." << std::endl;
}

Hammer::~Hammer(void)
{
	std::cout << "Hammer Destructor called." << std::endl;
}

void Hammer::use(void)
{
	this->numberOfUses -= 1;
	std::cout << "Hammer used! Remaining uses: " << this->numberOfUses << std::endl;
	if (this->numberOfUses == 0)
	{
		std::cout << "Hammer is broken! Deleting..." << std::endl;
		delete this;
	}
}
