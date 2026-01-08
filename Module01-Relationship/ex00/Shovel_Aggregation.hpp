#pragma once

#include <iostream>

class Shovel {

	private:
		int numberOfUses;

	public:
		Shovel();
		~Shovel();
		void use();
		int getNumberOfUses();

};