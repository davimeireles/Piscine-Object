#include "Bank.hpp"

/* Bank Constructor */
Bank::Bank()
{
	this->_liquidity = 0;
	std::cout << "Constructor Called" << "\n";
}

/* Bank Destructor */
Bank::~Bank()
{
	std::vector<Account *>::iterator it = _clients.begin();
	while (it != _clients.end())
	{
		delete *it;
		it++;
	}
	_clients.clear();
	std::cout << "Destructor Called" << "\n";
}

/* Function to create and add a new client into the bank. */
void Bank::addNewClient()
{
	_clients.push_back(new Account());
}

/* Function to find one account by ID */
std::vector<Account *>::iterator Bank::findClient(int id)
{
	std::vector<Account *>::iterator it = _clients.begin();
	for (; it < _clients.end(); it++)
	{
		if ((*it)->getID() == id)
			return (it);
	}
	return _clients.end();
}

/* Function to search and remove a client by id */
void Bank::removeCliente(int id)
{
	std::vector<Account *>::iterator it = findClient(id);
	if (it != _clients.end())
	{
		_clients.erase(it);
		std::cout << "Account removed from bank." << "\n";
	}
	else
		std::cout << "Account not found." << "\n";
}

void Bank::depositMoney(int id, double value)
{

	double inflow = 0.05;

	if (value <= 0)
	{
		std::cout << "Not possible to deposit negative or zero" << "\n";
		return;
	}

	std::vector<Account *>::iterator it = findClient(id);
	if (it != _clients.end())
	{
		double bankValue = value * inflow;
		this->_liquidity += bankValue;
		(*it)->_balance += value - bankValue;
		std::cout << std::fixed << std::setprecision(2);
		std::cout << "Deposited " << (value - bankValue) << " into client ID:" << id << "\n";
		std::cout << "New balance: " << (*it)->_balance << "\n";
	}
	else
		std::cout << "Account not found." << "\n";
}

/* Function to get bank liquidity */
double Bank::getLiquidity(void) const
{
	return this->_liquidity;
}

/* Function to give a loan to a customer */
void Bank::giveLoan(int id, double amount)
{

	if (amount <= 0)
	{
		std::cout << "Loan amount must be positive." << "\n";
		return;
	}

	if (this->_liquidity < amount)
	{
		std::cout << "Not enough liquidity to give a loan of " << amount << "\n";
		std::cout << "Bank liquidity: " << this->_liquidity << "\n";
		return;
	}

	std::vector<Account *>::iterator it = findClient(id);
	if (it != _clients.end())
	{
		this->_liquidity -= amount;
		(*it)->_balance += amount;
		std::cout << std::fixed << std::setprecision(2);
		std::cout << "Loan of " << amount << " given to client ID:" << id << "\n";
		std::cout << "New balance: " << (*it)->_balance << "\n";
		std::cout << "Bank liquidity: " << this->_liquidity << "\n";
	}
	else
		std::cout << "Account not found." << "\n";
}