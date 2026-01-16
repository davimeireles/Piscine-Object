#include <iostream>
#include "Worker_Inherence.hpp"
#include "Shovel_Inherence.hpp"
#include "Hammer_Inherence.hpp"

// Color definitions
#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"

int main(void)
{
	std::cout << BOLD << BLUE << "===== INHERITANCE & MULTIPLE TOOLS TEST =====" << RESET << std::endl
			  << std::endl;

	// ============= ABSTRACT CLASS TESTS =============
	std::cout << CYAN << "--- TOOL INHERITANCE TESTS ---" << RESET << std::endl
			  << std::endl;

	std::cout << CYAN << "TEST 1: Create a Shovel (Tool subclass)" << RESET << std::endl;
	Shovel *shovel = new Shovel();
	std::cout << GREEN << "✓ Shovel created" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "TEST 2: Create a Hammer (Tool subclass)" << RESET << std::endl;
	Hammer *hammer = new Hammer();
	std::cout << GREEN << "✓ Hammer created" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "TEST 3: Use Shovel via Tool interface" << RESET << std::endl;
	Tool *tool_ref = shovel;
	tool_ref->use();
	std::cout << GREEN << "✓ Polymorphic use() called" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "TEST 4: Use Hammer via Tool interface" << RESET << std::endl;
	tool_ref = hammer;
	tool_ref->use();
	std::cout << GREEN << "✓ Polymorphic use() called" << RESET << std::endl;
	std::cout << std::endl;

	// ============= WORKER WITH MULTIPLE TOOLS =============
	std::cout << CYAN << "--- WORKER WITH MULTIPLE TOOLS ---" << RESET << std::endl
			  << std::endl;

	std::cout << CYAN << "TEST 5: Create a worker" << RESET << std::endl;
	Worker_Inherence worker1;
	std::cout << std::endl;

	std::cout << CYAN << "TEST 6: Print worker data" << RESET << std::endl;
	worker1.print_object_data();
	std::cout << std::endl;

	std::cout << CYAN << "TEST 7: Create new tools for worker" << RESET << std::endl;
	Shovel *shovel2 = new Shovel();
	Hammer *hammer2 = new Hammer();
	std::cout << std::endl;

	std::cout << CYAN << "TEST 8: Equip multiple tools to worker" << RESET << std::endl;
	worker1.equip_tool(shovel2);
	worker1.equip_tool(hammer2);
	std::cout << std::endl;

	std::cout << CYAN << "TEST 9: List worker's tools" << RESET << std::endl;
	worker1.list_tools();
	std::cout << std::endl;

	std::cout << CYAN << "TEST 10: Use first tool (Shovel) multiple times" << RESET << std::endl;
	for (int i = 0; i < 3; i++)
	{
		worker1.use_tool(0);
	}
	std::cout << std::endl;

	std::cout << CYAN << "TEST 11: Use second tool (Hammer) multiple times" << RESET << std::endl;
	for (int i = 0; i < 2; i++)
	{
		worker1.use_tool(1);
	}
	std::cout << std::endl;

	std::cout << CYAN << "TEST 12: List tools after usage" << RESET << std::endl;
	worker1.list_tools();
	std::cout << std::endl;

	std::cout << CYAN << "TEST 13: Drop a tool by index" << RESET << std::endl;
	worker1.drop_tool(0);
	std::cout << std::endl;

	std::cout << CYAN << "TEST 14: List tools after dropping" << RESET << std::endl;
	worker1.list_tools();
	std::cout << std::endl;

	// ============= TOOL TRANSFER BETWEEN WORKERS =============
	std::cout << CYAN << "--- TOOL TRANSFER BETWEEN WORKERS ---" << RESET << std::endl
			  << std::endl;

	std::cout << CYAN << "TEST 15: Create second worker" << RESET << std::endl;
	Worker_Inherence worker2;
	std::cout << std::endl;

	std::cout << CYAN << "TEST 16: Create new tool" << RESET << std::endl;
	Shovel *shovel3 = new Shovel();
	std::cout << std::endl;

	std::cout << CYAN << "TEST 17: Give tool to worker1" << RESET << std::endl;
	worker1.equip_tool(shovel3);
	std::cout << std::endl;

	std::cout << CYAN << "TEST 18: Worker1 tools" << RESET << std::endl;
	worker1.list_tools();
	std::cout << std::endl;

	std::cout << CYAN << "TEST 19: Give same tool to worker2 (transfer)" << RESET << std::endl;
	worker2.equip_tool(shovel3);
	std::cout << std::endl;

	std::cout << CYAN << "TEST 20: Worker1 tools after transfer (should still have it in list)" << RESET << std::endl;
	worker1.list_tools();
	std::cout << std::endl;

	std::cout << CYAN << "TEST 21: Worker2 tools (should have the shovel)" << RESET << std::endl;
	worker2.list_tools();
	std::cout << std::endl;

	std::cout << CYAN << "TEST 22: Use tool from worker2" << RESET << std::endl;
	worker2.use_tool(0);
	std::cout << std::endl;

	// ============= TOOL DESTRUCTION =============
	std::cout << CYAN << "--- TOOL DESTRUCTION ---" << RESET << std::endl
			  << std::endl;

	std::cout << CYAN << "TEST 23: Use Hammer until destruction" << RESET << std::endl;
	Hammer *hammer3 = new Hammer();
	worker1.equip_tool(hammer3);
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Attempt #" << (i + 1) << ": ";
		worker1.use_tool(0);
	}
	std::cout << std::endl;

	std::cout << CYAN << "TEST 24: List worker1 tools after destruction" << RESET << std::endl;
	worker1.list_tools();
	std::cout << std::endl;

	// ============= CLEANUP =============
	std::cout << CYAN << "--- CLEANUP ---" << RESET << std::endl
			  << std::endl;
	std::cout << YELLOW << "Destroying workers and remaining tools..." << RESET << std::endl;
	std::cout << YELLOW << "(Tools should NOT be deleted when workers are deleted)" << RESET << std::endl;

	return (0);
}
