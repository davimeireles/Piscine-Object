#include <iostream>
#include "Vector2.hpp"
#include "Graph.hpp"

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
	std::cout << BOLD << BLUE << "===== GRAPH SYSTEM TEST =====" << RESET << std::endl
			  << std::endl;

	// Test 1: Create a graph
	std::cout << CYAN << "TEST 1: Creating a graph with size 5x5" << RESET << std::endl;
	Graph graph(5, 5);
	std::cout << std::endl;

	// Test 2: Add points to the graph
	std::cout << CYAN << "TEST 2: Adding points to the graph" << RESET << std::endl;
	graph.addPoint(0, 0);
	graph.addPoint(2, 2);
	graph.addPoint(4, 2);
	graph.addPoint(2, 4);
	std::cout << std::endl;

	// Test 3: Display the graph
	std::cout << CYAN << "TEST 3: Displaying the graph" << RESET << std::endl;
	graph.displayGraph();
	std::cout << std::endl;

	// Test 4: Get graph information
	std::cout << CYAN << "TEST 4: Graph information" << RESET << std::endl;
	std::cout << GREEN << "✓ Graph width: " << graph.getWidth() << RESET << std::endl;
	std::cout << GREEN << "✓ Graph height: " << graph.getHeight() << RESET << std::endl;
	std::cout << GREEN << "✓ Number of points: " << graph.getPointCount() << RESET << std::endl;
	std::cout << std::endl;

	// Test 5: Add more points
	std::cout << CYAN << "TEST 5: Adding more points" << RESET << std::endl;
	Vector2 point1(1, 1);
	Vector2 point2(3, 3);
	Vector2 point3(4, 4);

	graph.addPoint(point1);
	graph.addPoint(point2);
	graph.addPoint(point3);
	std::cout << std::endl;

	// Test 6: Display updated graph
	std::cout << CYAN << "TEST 6: Displaying updated graph" << RESET << std::endl;
	graph.displayGraph();
	std::cout << std::endl;

	// Test 7: Final point count
	std::cout << CYAN << "TEST 7: Final point count" << RESET << std::endl;
	std::cout << GREEN << "✓ Total points in graph: " << graph.getPointCount() << RESET << std::endl;
	std::cout << std::endl;

	// Test 8: Graph destruction
	std::cout << CYAN << "TEST 8: Graph destruction" << RESET << std::endl;
	std::cout << YELLOW << "--- Destroying graph ---" << RESET << std::endl;

	return (0);
}
