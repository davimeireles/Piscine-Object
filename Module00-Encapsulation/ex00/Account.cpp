#include "Account.hpp"

/* Account Constructor */
Account::Account() {
	this->_id = next_id++;
	this->_balance = 0;
	std::cout << "Account Constructor Called" << "\n";
	std::cout << "Client ID: " << this->_id << " Client Balance: " << this->_balance << "\n";
}

/* Account Destructor */
Account::~Account() {
	std::cout << "Account Destructor Called" << "\n";
}