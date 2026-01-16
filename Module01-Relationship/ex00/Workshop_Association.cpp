#include "Workshop_Association.hpp"
#include "Worker_Association.hpp"

Workshop::Workshop(std::string p_name) : name(p_name)
{
	std::cout << "Workshop '" << this->name << "' created." << std::endl;
}

Workshop::~Workshop(void)
{
	std::cout << "Workshop '" << this->name << "' destroyed." << std::endl;
}

void Workshop::registerWorker(Worker_Association *worker)
{
	if (worker == NULL)
	{
		std::cout << "Cannot register NULL worker!" << std::endl;
		return;
	}

	// Check if worker is already registered
	for (int i = 0; i < static_cast<int>(this->workers.size()); i++)
	{
		if (this->workers[i] == worker)
		{
			std::cout << "Worker already registered in workshop '" << this->name << "'!" << std::endl;
			return;
		}
	}

	this->workers.push_back(worker);
	worker->registerAtWorkshop(this);
	std::cout << "Worker registered at workshop '" << this->name << "'. Total workers: " << this->workers.size() << std::endl;
}

void Workshop::releaseWorker(Worker_Association *worker)
{
	if (worker == NULL)
	{
		std::cout << "Cannot release NULL worker!" << std::endl;
		return;
	}

	for (int i = 0; i < static_cast<int>(this->workers.size()); i++)
	{
		if (this->workers[i] == worker)
		{
			this->workers.erase(this->workers.begin() + i);
			worker->leaveWorkshop(this);
			std::cout << "Worker released from workshop '" << this->name << "'. Remaining workers: " << this->workers.size() << std::endl;
			return;
		}
	}

	std::cout << "Worker not found in workshop '" << this->name << "'!" << std::endl;
}

void Workshop::executeWorkDay(void) const
{
	std::cout << "\n=== Workshop '" << this->name << "' - Work Day Started ===" << std::endl;
	std::cout << "Number of workers: " << this->workers.size() << std::endl;

	for (int i = 0; i < static_cast<int>(this->workers.size()); i++)
	{
		this->workers[i]->work();
	}

	std::cout << "=== Work Day Ended ===" << std::endl
			  << std::endl;
}

int Workshop::getWorkerCount(void) const
{
	return this->workers.size();
}

void Workshop::listWorkers(void) const
{
	std::cout << "Workshop '" << this->name << "' workers (" << this->workers.size() << " total):" << std::endl;
	if (this->workers.size() == 0)
	{
		std::cout << "  (No workers registered)" << std::endl;
	}
	else
	{
		for (int i = 0; i < static_cast<int>(this->workers.size()); i++)
		{
			std::cout << "  [" << i << "] Worker" << std::endl;
		}
	}
}
