#pragma once

#include <iostream>

struct Position {
	int x;
	int y;
	int z;
};

struct Statistic {
	int level;
	int exp;
};

class Worker {
	
	private:
		Position pos;
		Statistic stat;

	public:
		Worker();
		~Worker();
		void print_object_data(void);
};