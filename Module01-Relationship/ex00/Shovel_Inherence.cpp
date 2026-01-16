#include "Shovel_Inherence.hpp"

Shovel::Shovel(void) : Tool()
{
	this->numberOfUses = 5;
	std::cout << "Shovel Constructor called with " << this->numberOfUses << " uses." << std::endl;
}

Shovel::~Shovel(void)
{
	std::cout << "Shovel Destructor called." << std::endl;
}

void Shovel::use(void)
{
	this->numberOfUses -= 1;
	std::cout << "Shovel used! Remaining uses: " << this->numberOfUses << std::endl;
	if (this->numberOfUses == 0)
	{
		std::cout << "Shovel is broken! Deleting..." << std::endl;
		delete this;
	}
}
