#include <iostream>
#include "Account.hpp"
#include "Bank.hpp"

int main()
{
	// Account creation

	Bank bank = Bank();
	bank.setBankLiquidity(999);
	bank.addNewClientAccount(&accountA);
	bank.addNewClientAccount(&accountB);

	bank.setBankLiquidity(bank.getBankLiquidity() - 200);

	std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;

	std::cout << "-----" << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}
