#include "Worker_Association.hpp"
#include "Workshop_Association.hpp"

Worker_Association::Worker_Association(std::string p_name) : name(p_name)
{
	std::cout << "Worker '" << this->name << "' created." << std::endl;
}

Worker_Association::~Worker_Association(void)
{
	std::cout << "Worker '" << this->name << "' destroyed." << std::endl;
}

void Worker_Association::registerAtWorkshop(Workshop *workshop)
{
	if (workshop == NULL)
	{
		std::cout << "Cannot register at NULL workshop!" << std::endl;
		return;
	}

	// Check if already registered
	for (int i = 0; i < static_cast<int>(this->workshops.size()); i++)
	{
		if (this->workshops[i] == workshop)
		{
			std::cout << "Worker '" << this->name << "' already registered at this workshop!" << std::endl;
			return;
		}
	}

	this->workshops.push_back(workshop);
}

void Worker_Association::leaveWorkshop(Workshop *workshop)
{
	if (workshop == NULL)
	{
		std::cout << "Cannot leave NULL workshop!" << std::endl;
		return;
	}

	for (int i = 0; i < static_cast<int>(this->workshops.size()); i++)
	{
		if (this->workshops[i] == workshop)
		{
			this->workshops.erase(this->workshops.begin() + i);
			std::cout << "Worker '" << this->name << "' left a workshop." << std::endl;
			return;
		}
	}
}

void Worker_Association::work(void) const
{
	std::cout << "  Worker '" << this->name << "' is working! (Registered at " << this->workshops.size() << " workshop(s))" << std::endl;
}

int Worker_Association::getWorkshopCount(void) const
{
	return this->workshops.size();
}

void Worker_Association::listWorkshops(void) const
{
	std::cout << "Worker '" << this->name << "' workshops (" << this->workshops.size() << " total):" << std::endl;
	if (this->workshops.size() == 0)
	{
		std::cout << "  (Not registered at any workshop)" << std::endl;
	}
	else
	{
		for (int i = 0; i < static_cast<int>(this->workshops.size()); i++)
		{
			std::cout << "  [" << i << "] Workshop" << std::endl;
		}
	}
}
