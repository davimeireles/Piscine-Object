#pragma once

#include <iostream>
#include <vector>

class Workshop;

class Worker_Association
{
private:
	std::string name;
	std::vector<Workshop *> workshops;

public:
	Worker_Association(std::string p_name);
	~Worker_Association(void);

	void registerAtWorkshop(Workshop *workshop);
	void leaveWorkshop(Workshop *workshop);
	void work(void) const;
	int getWorkshopCount(void) const;
	void listWorkshops(void) const;
};
