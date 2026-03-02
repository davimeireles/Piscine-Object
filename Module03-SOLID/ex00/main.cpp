#include "car.hpp"
#include <iostream>
#include <string>

// Color definitions
#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"

void printHeader(std::string title)
{
	std::cout << CYAN << "\n"
			  << BOLD;
	std::cout << "════════════════════════════════════════════════════════\n";
	std::cout << "  " << title << "\n";
	std::cout << "════════════════════════════════════════════════════════" << RESET << "\n\n";
}

void printTest(std::string testName)
{
	std::cout << BOLD << BLUE << "→ TEST: " << testName << RESET << "\n";
}

void printInfo(std::string info)
{
	std::cout << YELLOW << "   " << info << RESET << "\n";
}

void printSuccess(std::string msg)
{
	std::cout << GREEN << "   ✓ " << msg << RESET << "\n";
}

void waitForUser()
{
	std::cout << MAGENTA << "\n   [Press ENTER to continue...]" << RESET;
	std::cin.ignore(10000, '\n');
}

int main(void)
{
	printHeader("SOLID - SINGLE RESPONSIBILITY PRINCIPLE");
	printInfo("Car Class Demonstration");

	// Create a car
	Car myCar;

	// ============= TEST 1: ENGINE START =============
	printTest("Starting the Engine");
	printInfo("Calling: myCar.start()");
	myCar.start();
	waitForUser();

	// ============= TEST 2: ENGINE ALREADY ON =============
	printTest("Try Starting Engine Again");
	printInfo("Calling: myCar.start() [Already running]");
	myCar.start();
	waitForUser();

	// ============= TEST 3: ACCELERATION =============
	printTest("Accelerating the Car");
	printInfo("Calling: myCar.accelerate(50)");
	myCar.accelerate(50);
	printInfo("Calling: myCar.accelerate(30)");
	myCar.accelerate(30);
	waitForUser();

	// ============= TEST 4: SHIFT GEARS UP =============
	printTest("Shifting Gears Up");
	printInfo("Calling: myCar.shift_gears_up() [Multiple times]");
	for (int i = 0; i < 5; i++)
	{
		myCar.shift_gears_up();
	}
	waitForUser();

	// ============= TEST 5: SHIFT GEARS UP LIMIT =============
	printTest("Try Shifting Beyond Max Gear");
	printInfo("Calling: myCar.shift_gears_up() [At limit]");
	myCar.shift_gears_up();
	waitForUser();

	// ============= TEST 6: TURN WHEEL =============
	printTest("Turning the Wheels");
	printInfo("Calling: myCar.turn_wheel(1) [Turn right]");
	myCar.turn_wheel(1);
	printInfo("Calling: myCar.turn_wheel(1) [Turn right more]");
	myCar.turn_wheel(1);
	printInfo("Calling: myCar.turn_wheel(1) [Try to turn right - max angle]");
	myCar.turn_wheel(1);
	waitForUser();

	// ============= TEST 7: STRAIGHTEN WHEELS =============
	printTest("Straightening the Wheels");
	printInfo("Calling: myCar.straighten_wheels()");
	myCar.straighten_wheels();
	waitForUser();

	// ============= TEST 8: TURN LEFT =============
	printTest("Turning Wheels to the Left");
	printInfo("Calling: myCar.turn_wheel(-1) [Turn left]");
	myCar.turn_wheel(-1);
	printInfo("Calling: myCar.turn_wheel(-1) [Turn left more]");
	myCar.turn_wheel(-1);
	waitForUser();

	// ============= TEST 9: APPLY BRAKES =============
	printTest("Applying Brakes with Force");
	printInfo("Calling: myCar.apply_force_on_brakes(50)");
	myCar.apply_force_on_brakes(50);
	printInfo("Calling: myCar.apply_force_on_brakes(75)");
	myCar.apply_force_on_brakes(75);
	waitForUser();

	// ============= TEST 10: SHIFT DOWN =============
	printTest("Shifting Gears Down");
	printInfo("Calling: myCar.shift_gears_down() [Multiple times]");
	for (int i = 0; i < 3; i++)
	{
		myCar.shift_gears_down();
	}
	waitForUser();

	// ============= TEST 11: REVERSE =============
	printTest("Engaging Reverse Gear");
	printInfo("Calling: myCar.reverse()");
	myCar.reverse();
	printInfo("Calling: myCar.accelerate(-20)");
	myCar.accelerate(-20);
	waitForUser();

	// ============= TEST 12: EMERGENCY BRAKES =============
	printTest("Emergency Braking System");
	printInfo("Calling: myCar.apply_emergency_brakes()");
	myCar.apply_emergency_brakes();
	waitForUser();

	// ============= TEST 13: STOP ENGINE =============
	printTest("Stopping the Engine");
	printInfo("Calling: myCar.stop()");
	myCar.stop();
	waitForUser();

	// ============= FINAL SUMMARY =============
	printHeader("SINGLE RESPONSIBILITY PRINCIPLE - SUMMARY");

	std::cout << GREEN << BOLD << "✓ Architecture Breakdown:\n"
			  << RESET;
	std::cout << CYAN << "  • Engine Class" << RESET << " → Manages engine state (start/stop)\n";
	std::cout << CYAN << "  • Transmission Class" << RESET << " → Manages gear shifting\n";
	std::cout << CYAN << "  • Brakes Class" << RESET << " → Manages braking force\n";
	std::cout << CYAN << "  • Wheels Class" << RESET << " → Manages wheel direction\n";
	std::cout << CYAN << "  • Car Class" << RESET << " → Coordinates all components\n";

	std::cout << "\n"
			  << YELLOW << BOLD << "Why Single Responsibility?\n"
			  << RESET;
	std::cout << "  1. Each class has ONE reason to change\n";
	std::cout << "  2. Easy to test individual components\n";
	std::cout << "  3. Easy to modify one system without affecting others\n";
	std::cout << "  4. Better code organization and maintainability\n";

	std::cout << "\n"
			  << GREEN << BOLD << "✓ All tests completed successfully!\n"
			  << RESET;
	std::cout << RESET << "\n";

	return (0);
}
