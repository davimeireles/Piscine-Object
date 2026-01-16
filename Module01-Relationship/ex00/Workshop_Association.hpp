#pragma once

#include <iostream>
#include <vector>

class Worker_Association;

class Workshop
{
private:
	std::string name;
	std::vector<Worker_Association *> workers;

public:
	Workshop(std::string p_name);
	~Workshop(void);

	void registerWorker(Worker_Association *worker);
	void releaseWorker(Worker_Association *worker);
	void executeWorkDay(void) const;
	int getWorkerCount(void) const;
	void listWorkers(void) const;
};
