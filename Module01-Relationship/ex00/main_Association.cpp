#include <iostream>
#include "Workshop_Association.hpp"
#include "Worker_Association.hpp"

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
	std::cout << BOLD << BLUE << "===== ASSOCIATION PATTERN TEST =====" << RESET << std::endl
			  << std::endl;

	// ============= WORKSHOP CREATION =============
	std::cout << CYAN << "--- WORKSHOP CREATION ---" << RESET << std::endl
			  << std::endl;

	std::cout << CYAN << "TEST 1: Create workshops" << RESET << std::endl;
	Workshop workshop1("Construction");
	Workshop workshop2("Repair");
	Workshop workshop3("Maintenance");
	std::cout << std::endl;

	// ============= WORKER CREATION =============
	std::cout << CYAN << "--- WORKER CREATION ---" << RESET << std::endl
			  << std::endl;

	std::cout << CYAN << "TEST 2: Create workers" << RESET << std::endl;
	Worker_Association worker1("Alice");
	Worker_Association worker2("Bob");
	Worker_Association worker3("Charlie");
	std::cout << std::endl;

	// ============= SINGLE WORKSHOP REGISTRATION =============
	std::cout << CYAN << "--- SINGLE WORKSHOP REGISTRATION ---" << RESET << std::endl
			  << std::endl;

	std::cout << CYAN << "TEST 3: Register worker1 at workshop1" << RESET << std::endl;
	workshop1.registerWorker(&worker1);
	std::cout << std::endl;

	std::cout << CYAN << "TEST 4: Register worker2 at workshop1" << RESET << std::endl;
	workshop1.registerWorker(&worker2);
	std::cout << std::endl;

	std::cout << CYAN << "TEST 5: List workers in workshop1" << RESET << std::endl;
	workshop1.listWorkers();
	std::cout << std::endl;

	std::cout << CYAN << "TEST 6: List workshops for worker1" << RESET << std::endl;
	worker1.listWorkshops();
	std::cout << std::endl;

	// ============= MULTIPLE WORKSHOP REGISTRATION =============
	std::cout << CYAN << "--- MULTIPLE WORKSHOP REGISTRATION ---" << RESET << std::endl
			  << std::endl;

	std::cout << CYAN << "TEST 7: Register worker1 at workshop2 (same worker, different workshop)" << RESET << std::endl;
	workshop2.registerWorker(&worker1);
	std::cout << std::endl;

	std::cout << CYAN << "TEST 8: Register worker1 at workshop3" << RESET << std::endl;
	workshop3.registerWorker(&worker1);
	std::cout << std::endl;

	std::cout << CYAN << "TEST 9: List all workshops for worker1 (should have 3)" << RESET << std::endl;
	worker1.listWorkshops();
	std::cout << GREEN << "✓ Worker1 is registered at " << worker1.getWorkshopCount() << " workshops" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "TEST 10: Register worker2 and worker3 at additional workshops" << RESET << std::endl;
	workshop2.registerWorker(&worker2);
	workshop2.registerWorker(&worker3);
	workshop3.registerWorker(&worker2);
	workshop3.registerWorker(&worker3);
	std::cout << std::endl;

	// ============= WORKSHOP EXECUTE WORK DAY =============
	std::cout << CYAN << "--- EXECUTE WORK DAY ---" << RESET << std::endl
			  << std::endl;

	std::cout << CYAN << "TEST 11: Execute work day at workshop1" << RESET << std::endl;
	workshop1.executeWorkDay();

	std::cout << CYAN << "TEST 12: Execute work day at workshop2" << RESET << std::endl;
	workshop2.executeWorkDay();

	std::cout << CYAN << "TEST 13: Execute work day at workshop3" << RESET << std::endl;
	workshop3.executeWorkDay();

	// ============= WORKER RELEASE FROM WORKSHOP =============
	std::cout << CYAN << "--- WORKER RELEASE FROM WORKSHOP ---" << RESET << std::endl
			  << std::endl;

	std::cout << CYAN << "TEST 14: Release worker1 from workshop1" << RESET << std::endl;
	workshop1.releaseWorker(&worker1);
	std::cout << std::endl;

	std::cout << CYAN << "TEST 15: Verify worker1 still at other workshops" << RESET << std::endl;
	worker1.listWorkshops();
	std::cout << GREEN << "✓ Worker1 still registered at " << worker1.getWorkshopCount() << " workshops" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "TEST 16: List workers in workshop1 after release" << RESET << std::endl;
	workshop1.listWorkers();
	std::cout << std::endl;

	std::cout << CYAN << "TEST 17: Release worker1 from all remaining workshops" << RESET << std::endl;
	workshop2.releaseWorker(&worker1);
	workshop3.releaseWorker(&worker1);
	std::cout << std::endl;

	std::cout << CYAN << "TEST 18: Verify worker1 has no workshops" << RESET << std::endl;
	worker1.listWorkshops();
	std::cout << std::endl;

	// ============= EDGE CASES =============
	std::cout << CYAN << "--- EDGE CASES ---" << RESET << std::endl
			  << std::endl;

	std::cout << CYAN << "TEST 19: Try to register same worker twice at same workshop" << RESET << std::endl;
	workshop1.registerWorker(&worker2);
	workshop1.registerWorker(&worker2);
	std::cout << std::endl;

	std::cout << CYAN << "TEST 20: Try to release worker not at workshop" << RESET << std::endl;
	workshop1.releaseWorker(&worker1);
	std::cout << std::endl;

	std::cout << CYAN << "TEST 21: Try to release worker from empty workshop" << RESET << std::endl;
	workshop1.releaseWorker(&worker3);
	std::cout << std::endl;

	// ============= FINAL STATE =============
	std::cout << CYAN << "--- FINAL STATE ---" << RESET << std::endl
			  << std::endl;

	std::cout << CYAN << "TEST 22: Final workshop counts" << RESET << std::endl;
	std::cout << "Workshop1 workers: " << workshop1.getWorkerCount() << std::endl;
	std::cout << "Workshop2 workers: " << workshop2.getWorkerCount() << std::endl;
	std::cout << "Workshop3 workers: " << workshop3.getWorkerCount() << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "TEST 23: Final work day executions" << RESET << std::endl;
	workshop1.executeWorkDay();
	workshop2.executeWorkDay();
	workshop3.executeWorkDay();

	// ============= CLEANUP =============
	std::cout << CYAN << "--- CLEANUP ---" << RESET << std::endl
			  << std::endl;
	std::cout << YELLOW << "All objects will be destroyed..." << RESET << std::endl;
	std::cout << YELLOW << "(Workers and Workshops are independently destroyed)" << RESET << std::endl;

	return (0);
}
