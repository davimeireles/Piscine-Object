#include "Vector2.hpp"

/* Vector2 Default Constructor */
Vector2::Vector2(void) : x(0.0f), y(0.0f)
{
}

/* Vector2 Constructor with parameters */
Vector2::Vector2(float p_x, float p_y) : x(p_x), y(p_y)
{
}

/* Vector2 Destructor */
Vector2::~Vector2(void)
{
}

/* Getter for X coordinate */
float Vector2::getX(void) const
{
	return this->x;
}

/* Getter for Y coordinate */
float Vector2::getY(void) const
{
	return this->y;
}

/* Setter for X coordinate */
void Vector2::setX(float p_x)
{
	this->x = p_x;
}

/* Setter for Y coordinate */
void Vector2::setY(float p_y)
{
	this->y = p_y;
}
