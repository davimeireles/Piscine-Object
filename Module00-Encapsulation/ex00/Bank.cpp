#include "Bank.hpp"

/* Bank Constructor */
Bank::Bank() {
	this->_liquidity = 0;
	this->_clients = {};
	std::cout << "Constructor Called" << "\n";
}

/* Bank Destructor */
Bank::~Bank() {
	std::cout << "Destructor Called" << "\n";	
}

/* Function to create and add a new client into the bank. */
void Bank::addNewClient(float balance) {
	_clients.push_back(new Account(balance));
}