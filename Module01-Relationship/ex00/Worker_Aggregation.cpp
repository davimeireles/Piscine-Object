#include "Worker_Aggregation.hpp"

Worker::Worker()
{
	pos.x = 10;
	pos.y = 20;
	pos.z = 1;

	stat.exp = 20;
	stat.level = 100;

	this->shovel = NULL;
	std::cout << "Worker Constructor called." << std::endl;
}

Worker::~Worker()
{
	std::cout << "Destructor called." << std::endl;
}

void Worker::print_object_data(void)
{
	std::cout << "Display of object values" << std::endl;
	std::cout << "Position X: " << this->pos.x << std::endl;
	std::cout << "Position Y: " << this->pos.y << std::endl;
	std::cout << "Position Z: " << this->pos.z << std::endl;

	std::cout << "Statistic Exp: " << this->stat.exp << std::endl;
	std::cout << "Statistic Level: " << this->stat.level << std::endl;
}

void Worker::equip_shovel(Shovel *shovel)
{
	this->shovel = shovel;
	std::cout << "Worker equipped Shovel and can use " << this->shovel->getNumberOfUses() << " times" << std::endl;
}

void Worker::use_shovel(void)
{
	if (this->shovel == nullptr)
	{
		std::cout << "Worker has no shovel to use!" << std::endl;
		return;
	}
	this->shovel->use();
	if (this->shovel->getNumberOfUses() == 0)
	{
		this->shovel = nullptr;
		std::cout << "Worker's shovel was destroyed!" << std::endl;
	}
}

void Worker::drop_shovel()
{
	if (this->shovel == nullptr)
	{
		std::cout << "Worker has no shovel to drop!" << std::endl;
		return;
	}
	std::cout << "Worker dropped Shovel with remaining " << this->shovel->getNumberOfUses() << " uses" << std::endl;
	this->shovel = nullptr;
}