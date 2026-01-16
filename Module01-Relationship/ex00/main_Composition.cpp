#include <iostream>
#include "Worker_Composition.hpp"

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
	std::cout << BOLD << BLUE << "===== COMPOSITION PATTERN TEST =====" << RESET << std::endl
			  << std::endl;

	std::cout << CYAN << "TEST 1: Create a worker (Composition)" << RESET << std::endl;
	Worker worker;
	std::cout << std::endl;

	std::cout << CYAN << "TEST 2: Print worker data" << RESET << std::endl;
	worker.print_object_data();
	std::cout << std::endl;

	std::cout << CYAN << "TEST 3: Worker destruction (composition means tools are also destroyed)" << RESET << std::endl;
	std::cout << YELLOW << "Worker will be destroyed now..." << RESET << std::endl;
	{
		Worker temp_worker;
		std::cout << "Temp worker created" << std::endl;
	}
	std::cout << YELLOW << "Temp worker destroyed - in composition, child objects are deleted too" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "--- CLEANUP ---" << RESET << std::endl
			  << std::endl;
	std::cout << YELLOW << "Main worker will be destroyed..." << RESET << std::endl;

	return (0);
}
