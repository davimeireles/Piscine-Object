#pragma once

#include <iostream>
#include "Shovel_Aggregation.hpp"

struct Position
{
	int x;
	int y;
	int z;
};

struct Statistic
{
	int level;
	int exp;
};

class Worker
{

private:
	Position pos;
	Statistic stat;
	Shovel *shovel;

public:
	Worker();
	~Worker();
	void print_object_data(void);
	void equip_shovel(Shovel *shovel);
	void use_shovel(void);
	void drop_shovel();
};