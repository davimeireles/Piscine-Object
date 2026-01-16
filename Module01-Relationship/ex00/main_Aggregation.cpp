#include <iostream>
#include "Worker_Aggregation.hpp"

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
	std::cout << BOLD << BLUE << "===== WORKER & SHOVEL SYSTEM TEST =====" << RESET << std::endl
			  << std::endl;

	// ============= SHOVEL TESTS =============
	std::cout << CYAN << "--- SHOVEL TESTS ---" << RESET << std::endl
			  << std::endl;

	std::cout << CYAN << "TEST 1: Create a shovel" << RESET << std::endl;
	Shovel *shovel1 = new Shovel();
	std::cout << GREEN << "✓ Shovel created with " << shovel1->getNumberOfUses() << " uses" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "TEST 2: Use shovel once" << RESET << std::endl;
	shovel1->use();
	std::cout << GREEN << "✓ Remaining uses: " << shovel1->getNumberOfUses() << RESET << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "TEST 3: Use shovel multiple times" << RESET << std::endl;
	for (int i = 0; i < 3; i++)
	{
		shovel1->use();
	}
	std::cout << GREEN << "✓ Remaining uses: " << shovel1->getNumberOfUses() << RESET << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "TEST 4: Use shovel until destruction (5th use)" << RESET << std::endl;
	shovel1->use();
	std::cout << std::endl;

	// ============= WORKER TESTS =============
	std::cout << CYAN << "--- WORKER TESTS ---" << RESET << std::endl
			  << std::endl;

	std::cout << CYAN << "TEST 5: Create a worker" << RESET << std::endl;
	Worker worker;
	std::cout << std::endl;

	std::cout << CYAN << "TEST 6: Print worker data" << RESET << std::endl;
	worker.print_object_data();
	std::cout << std::endl;

	// ============= WORKER + SHOVEL AGGREGATION TESTS =============
	std::cout << CYAN << "--- AGGREGATION TESTS ---" << RESET << std::endl
			  << std::endl;

	std::cout << CYAN << "TEST 7: Create new shovel for worker" << RESET << std::endl;
	Shovel *shovel2 = new Shovel();
	std::cout << std::endl;

	std::cout << CYAN << "TEST 8: Equip shovel to worker" << RESET << std::endl;
	worker.equip_shovel(shovel2);
	std::cout << std::endl;

	std::cout << CYAN << "TEST 9: Worker uses shovel 5 times (should destroy after 5th use)" << RESET << std::endl;
	for (int i = 1; i <= 6; i++)
	{
		std::cout << YELLOW << "\n--- Use #" << i << " ---" << RESET << std::endl;
		worker.use_shovel();
	}
	std::cout << std::endl;

	std::cout << CYAN << "TEST 10: Try to use shovel after destruction" << RESET << std::endl;
	worker.use_shovel();
	std::cout << std::endl;

	// ============= DROP SHOVEL TESTS =============
	std::cout << CYAN << "--- DROP SHOVEL TESTS ---" << RESET << std::endl
			  << std::endl;

	std::cout << CYAN << "TEST 11: Try to drop shovel (should fail - already destroyed)" << RESET << std::endl;
	worker.drop_shovel();
	std::cout << std::endl;

	std::cout << CYAN << "TEST 12: Create another shovel and equip" << RESET << std::endl;
	Shovel *shovel3 = new Shovel();
	worker.equip_shovel(shovel3);
	std::cout << std::endl;

	std::cout << CYAN << "TEST 13: Drop shovel before using it" << RESET << std::endl;
	worker.drop_shovel();
	std::cout << std::endl;

	std::cout << CYAN << "TEST 14: Try to drop shovel again (should fail - no shovel)" << RESET << std::endl;
	worker.drop_shovel();
	std::cout << std::endl;

	// ============= MULTIPLE WORKERS + SHOVEL TRANSFER TESTS =============
	std::cout << CYAN << "--- MULTIPLE WORKERS + SHOVEL TRANSFER ---" << RESET << std::endl
			  << std::endl;

	std::cout << CYAN << "TEST 15: Create two workers and one shovel" << RESET << std::endl;
	Worker worker2;
	Shovel *shovel4 = new Shovel();
	std::cout << std::endl;

	std::cout << CYAN << "TEST 16: Give shovel to worker1" << RESET << std::endl;
	worker.equip_shovel(shovel4);
	std::cout << std::endl;

	std::cout << CYAN << "TEST 17: Worker1 uses shovel once" << RESET << std::endl;
	worker.use_shovel();
	std::cout << GREEN << "✓ Shovel now has " << shovel4->getNumberOfUses() << " uses remaining" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "TEST 18: Give the SAME shovel to worker2 (should remove from worker1)" << RESET << std::endl;
	worker2.equip_shovel(shovel4);
	std::cout << std::endl;

	std::cout << CYAN << "TEST 19: Verify worker1 no longer has the shovel" << RESET << std::endl;
	worker.use_shovel();
	std::cout << std::endl;

	std::cout << CYAN << "TEST 20: Verify worker2 now has the shovel" << RESET << std::endl;
	worker2.use_shovel();
	std::cout << GREEN << "✓ Shovel now has " << shovel4->getNumberOfUses() << " uses remaining" << RESET << std::endl;
	std::cout << std::endl;

	// ============= WORKER DESTRUCTION TEST =============
	std::cout << CYAN << "--- WORKER DESTRUCTION TEST ---" << RESET << std::endl
			  << std::endl;

	std::cout << CYAN << "TEST 21: Drop shovel from worker2" << RESET << std::endl;
	worker2.drop_shovel();
	std::cout << std::endl;

	std::cout << CYAN << "TEST 22: Delete worker2 (shovel should NOT be destroyed)" << RESET << std::endl;
	std::cout << YELLOW << "Worker2 will be destroyed now..." << RESET << std::endl;
	{
		Worker *temp_worker = new Worker();
		temp_worker->equip_shovel(shovel4);
		std::cout << "Temp worker created with shovel" << std::endl;
		delete temp_worker;
		std::cout << YELLOW << "Temp worker deleted - shovel should still exist!" << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << CYAN << "TEST 23: Verify shovel4 still exists and can be used" << RESET << std::endl;
	shovel4->use();
	std::cout << GREEN << "✓ Shovel still exists with " << shovel4->getNumberOfUses() << " uses remaining" << RESET << std::endl;
	std::cout << std::endl;

	// ============= CLEANUP =============
	std::cout << CYAN << "--- CLEANUP ---" << RESET << std::endl
			  << std::endl;
	std::cout << YELLOW << "Deleting shovel4 manually (since Worker didn't delete it)..." << RESET << std::endl;
	delete shovel4;
	std::cout << YELLOW << "Worker and remaining objects will be destroyed..." << RESET << std::endl;

	return (0);
}
