#include "Account.hpp"

/* Initialize static member */
int Account::next_id = 0;

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

/* Function to return Client ID */
int Account::getID() {
	return this->_id;
}

/* Function to return Client balance */
double Account::getBalance() {
	return this->_balance;
}