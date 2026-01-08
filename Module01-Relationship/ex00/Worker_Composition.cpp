#include "Worker_Composition.hpp"

Worker::Worker() {
	pos.x = 10;
	pos.y = 20;
	pos.z = 1;

	stat.exp = 20;
	stat.level = 100;
	std::cout << "Worker Constructor called." << std::endl;
}

Worker::~Worker() {
	std::cout << "Destructor called." << std::endl;
}

void Worker::print_object_data(void) {
	std::cout << "Display of object values" << std::endl;
	std::cout << "Position X: " << this->pos.x << std::endl; 
	std::cout << "Position Y: " << this->pos.y << std::endl; 
	std::cout << "Position Z: " << this->pos.z << std::endl; 

	std::cout << "Statistic Exp: " << this->stat.exp << std::endl; 
	std::cout << "Statistic Level: " << this->stat.level << std::endl; 
}