#include "Worker_Inherence.hpp"

Worker_Inherence::Worker_Inherence(void)
{
	pos.x = 10;
	pos.y = 20;
	pos.z = 1;

	stat.exp = 20;
	stat.level = 100;

	std::cout << "Worker_Inherence Constructor called." << std::endl;
}

Worker_Inherence::~Worker_Inherence(void)
{
	std::cout << "Worker_Inherence Destructor called." << std::endl;
}

void Worker_Inherence::print_object_data(void) const
{
	std::cout << "Display of object values" << std::endl;
	std::cout << "Position X: " << this->pos.x << std::endl;
	std::cout << "Position Y: " << this->pos.y << std::endl;
	std::cout << "Position Z: " << this->pos.z << std::endl;

	std::cout << "Statistic Exp: " << this->stat.exp << std::endl;
	std::cout << "Statistic Level: " << this->stat.level << std::endl;
}

void Worker_Inherence::equip_tool(Tool *tool)
{
	if (tool == NULL)
	{
		std::cout << "Cannot equip NULL tool!" << std::endl;
		return;
	}
	this->tools.push_back(tool);
	std::cout << "Worker equipped tool with " << tool->getNumberOfUses() << " uses. Total tools: " << this->tools.size() << std::endl;
}

void Worker_Inherence::use_tool(int index)
{
	if (index < 0 || index >= static_cast<int>(this->tools.size()))
	{
		std::cout << "Invalid tool index: " << index << std::endl;
		return;
	}
	if (this->tools[index] == NULL)
	{
		std::cout << "Tool at index " << index << " is NULL!" << std::endl;
		return;
	}
	this->tools[index]->use();

	if (this->tools[index]->getNumberOfUses() == 0)
	{
		this->tools.erase(this->tools.begin() + index);
		std::cout << "Tool destroyed and removed from worker's inventory." << std::endl;
	}
}

void Worker_Inherence::drop_tool(int index)
{
	if (index < 0 || index >= static_cast<int>(this->tools.size()))
	{
		std::cout << "Invalid tool index: " << index << std::endl;
		return;
	}
	std::cout << "Worker dropped tool at index " << index << " with remaining " << this->tools[index]->getNumberOfUses() << " uses" << std::endl;
	this->tools.erase(this->tools.begin() + index);
}

void Worker_Inherence::list_tools(void) const
{
	std::cout << "Worker's tools (" << this->tools.size() << " total):" << std::endl;
	for (int i = 0; i < static_cast<int>(this->tools.size()); i++)
	{
		std::cout << "  [" << i << "] Tool with " << this->tools[i]->getNumberOfUses() << " uses" << std::endl;
	}
}

int Worker_Inherence::get_tool_count(void) const
{
	return this->tools.size();
}
