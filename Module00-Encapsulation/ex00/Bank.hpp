#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "Account.hpp"

struct Bank
{

private:
	int _liquidity;
	std::vector<Account *> _clients;

public:
	Bank();
	~Bank();
	void addNewClient(void);

	std::vector<Account *>::iterator findClient(int id);

	void removeCliente(int id);
	void depositMoney(int id, double value);

	double getLiquidity(void) const;
	void giveLoan(int id, double amount);
};