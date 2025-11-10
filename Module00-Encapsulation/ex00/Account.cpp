#include "Account.hpp"

/* Account Constructor */
Account::Account(float balance) {
	this->_id = next_id++;
	this->_value = balance;
	std::cout << "Account Constructor Called" << "\n";
}

/* Account Destructor */
Account::~Account() {
	std::cout << "Account Destructor Called" << "\n";
}