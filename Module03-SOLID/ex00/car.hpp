#pragma once

#include <iostream>

class Engine
{

	bool engineStatus;

public:
	Engine() : engineStatus(false) {}
	~Engine() {}
	void start()
	{
		if (!engineStatus)
		{
			engineStatus = true;
			std::cout << "Engine On!" << std::endl;
		}
		else
			std::cout << "Engine already On you can ride your car." << std::endl;
	}

	void stop()
	{
		engineStatus = false;
		std::cout << "Engine Off!" << std::endl;
	}
};

class Transmission
{

	int32_t gear;

public:
	Transmission() : gear(0) {}
	~Transmission() {}

	void shiftUp()
	{
		if (gear <= 5)
		{
			std::cout << "Shifted gear up, current guear: " << gear << std::endl;
			gear++;
		}
		else
			std::cout << "** NOISE NOISE NOISE NOISE NOISE NOISE NOISE NOISE NOISE **" << std::endl;
	}

	void shiftDown()
	{
		if (gear > 0)
		{
			std::cout << "Shifted gear down, current guear: " << gear << std::endl;
			gear--;
		}
		else
			std::cout << "** DEADBEEF **" << std::endl;
	}

	void reverse()
	{
		gear = -1;
		std::cout << "Reverse Gear ON. " << std::endl;
	}
};

class Wheels
{

	int32_t direction;

public:
	Wheels() : direction(0) {}
	~Wheels() {}

	void turn(int32_t angle)
	{

		if (direction == 3 || direction == -3)
		{
			std::cout << "Max Angle Reached" << std::endl;
			return;
		}

		if (angle > 1 || angle < -1 || angle == 0)
			std::cout << "You can only turn the wheel for left or right.";
		else if (angle == 1)
		{
			direction += 1;
			std::cout << "Turning the wheel to the right." << std::endl;
		}
		else if (angle == -1)
		{
			direction -= 1;
			std::cout << "Turning the wheel to the left." << std::endl;
		}
	}

	void straighten()
	{
		direction = 0;
		std::cout << "Wheels back to a straight-ahead position." << std::endl;
	}
};

class Brakes
{

	float maxForce;

public:
	Brakes() : maxForce(100) {}
	~Brakes() {}
	void applyForce(float force)
	{
		(void)maxForce;
		std::cout << "Brakes applied with force " << force << "\n";
	}
	void emergencyStop()
	{
		std::cout << "EMERGENCY BRAKES! Max force applied!\n";
	}
};

class Car
{
private:
	Engine engine;
	Transmission transmission;
	Brakes brakes;
	Wheels wheels;
	int speed;

public:
	Car() : speed(0) {}

	// Delegates to components
	void start() { engine.start(); }
	void stop()
	{
		engine.stop();
		brakes.emergencyStop();
	}
	void accelerate(int value)
	{
		if (value <= 0)
		{
			std::cout << "We can't increase by negative value or zero. " << std::endl;
			return;
		}
		speed += value;
		std::cout << "Speed increased by " << value << "\n";
	}
	void shift_gears_up() { transmission.shiftUp(); }
	void shift_gears_down() { transmission.shiftDown(); }
	void reverse() { transmission.reverse(); }
	void turn_wheel(float angle) { wheels.turn(angle); }
	void straighten_wheels() { wheels.straighten(); }
	void apply_force_on_brakes(float force) { brakes.applyForce(force); }
	void apply_emergency_brakes() { brakes.emergencyStop(); }
};