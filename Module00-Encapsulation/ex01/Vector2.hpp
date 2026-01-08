#pragma once

#include <iostream>

struct Vector2
{
	float x;
	float y;

	Vector2(void);
	Vector2(float p_x, float p_y);
	~Vector2(void);

	float getX(void) const;
	float getY(void) const;
	void setX(float p_x);
	void setY(float p_y);
};
