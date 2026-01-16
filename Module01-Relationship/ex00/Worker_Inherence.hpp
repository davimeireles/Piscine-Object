#pragma once

#include <iostream>
#include <vector>
#include "Tool_Inherence.hpp"

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

class Worker_Inherence
{
private:
	Position pos;
	Statistic stat;
	std::vector<Tool *> tools;

public:
	Worker_Inherence(void);
	~Worker_Inherence(void);

	void print_object_data(void) const;
	void equip_tool(Tool *tool);
	void use_tool(int index);
	void drop_tool(int index);
	void list_tools(void) const;
	int get_tool_count(void) const;
};
