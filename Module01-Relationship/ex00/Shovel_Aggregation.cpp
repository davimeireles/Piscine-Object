#include "Shovel_Aggregation.hpp"

Shovel::Shovel()
{
	this->numberOfUses = 5;
	std::cout << "Shovel Constructor called." << std::endl;
}

Shovel::~Shovel()
{
	std::cout << "Shovel Destructor called." << std::endl;
}

void Shovel::use()
{
	this->numberOfUses -= 1;
	std::cout << "Shovel used! Remaining uses: " << this->numberOfUses << std::endl;
	if (this->numberOfUses == 0)
	{
		std::cout << "Shovel is broken! Deleting..." << std::endl;
		delete this;
	}
}

int Shovel::getNumberOfUses()
{
	return this->numberOfUses;
}