#pragma once

#include <iostream>
#include <vector>
#include "Vector2.hpp"

struct Graph
{
private:
	Vector2 _size;
	std::vector<Vector2> _points;

public:
	Graph(float width, float height);
	~Graph(void);

	void addPoint(float x, float y);
	void addPoint(Vector2 point);
	void displayGraph(void) const;

	float getWidth(void) const;
	float getHeight(void) const;
	int getPointCount(void) const;
};
