#include "Graph.hpp"

/* Graph Constructor */
Graph::Graph(float width, float height) : _size(width, height)
{
	std::cout << "Graph created with size: " << width << " x " << height << std::endl;
}

/* Graph Destructor */
Graph::~Graph(void)
{
	_points.clear();
	std::cout << "Graph destroyed" << std::endl;
}

/* Add a point to the graph using coordinates */
void Graph::addPoint(float x, float y)
{
	Vector2 point(x, y);
	_points.push_back(point);
	std::cout << "Point added at (" << x << ", " << y << ")" << std::endl;
}

/* Add a point to the graph using Vector2 */
void Graph::addPoint(Vector2 point)
{
	_points.push_back(point);
	std::cout << "Point added at (" << point.getX() << ", " << point.getY() << ")" << std::endl;
}

/* Get graph width */
float Graph::getWidth(void) const
{
	return _size.getX();
}

/* Get graph height */
float Graph::getHeight(void) const
{
	return _size.getY();
}

/* Get number of points */
int Graph::getPointCount(void) const
{
	return _points.size();
}

/* Display the graph as ASCII art */
void Graph::displayGraph(void) const
{
	int width = static_cast<int>(_size.getX());
	int height = static_cast<int>(_size.getY());

	// Display graph from top to bottom
	for (int y = height; y >= 0; y--)
	{
		// Display Y axis label
		std::cout << ">& " << y << " ";

		// Display each point in the row
		for (int x = 0; x <= width; x++)
		{
			bool pointExists = false;

			// Check if there's a point at this position
			for (int i = 0; i < static_cast<int>(_points.size()); i++)
			{
				int px = static_cast<int>(_points[i].getX());
				int py = static_cast<int>(_points[i].getY());
				if (px == x && py == y)
				{
					std::cout << "X";
					pointExists = true;
					break;
				}
			}

			if (!pointExists)
			{
				std::cout << ".";
			}

			// Add space between cells
			if (x < width)
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}

	// Display X axis
	std::cout << ">& ";
	for (int x = 0; x <= width; x++)
	{
		std::cout << x;
		if (x < width)
		{
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}
