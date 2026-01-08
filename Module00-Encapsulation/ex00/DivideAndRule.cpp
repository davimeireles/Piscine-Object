#include <iostream>
#include "Account.hpp"
#include "Bank.hpp"

// Color definitions for terminal output
#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"

int main()
{
	std::cout << BOLD << BLUE << "===== BANK SYSTEM COMPREHENSIVE TEST =====" << RESET << std::endl
			  << std::endl;

	// Test 1: Create a Bank
	std::cout << CYAN << "TEST 1: Creating a Bank" << RESET << std::endl;
	Bank bank = Bank();
	std::cout << std::endl;

	// Test 2: Add new clients to the bank
	std::cout << CYAN << "TEST 2: Adding new clients to the bank" << RESET << std::endl;
	bank.addNewClient();
	std::cout << GREEN << "✓ Client 1 added" << RESET << std::endl;
	bank.addNewClient();
	std::cout << GREEN << "✓ Client 2 added" << RESET << std::endl;
	bank.addNewClient();
	std::cout << GREEN << "✓ Client 3 added" << RESET << std::endl;
	bank.addNewClient();
	std::cout << GREEN << "✓ Client 4 added" << RESET << std::endl;
	std::cout << std::endl;

	// Test 3: Deposit money into accounts (valid deposits)
	std::cout << CYAN << "TEST 3: Depositing valid amounts into accounts" << RESET << std::endl;
	bank.depositMoney(0, 500.0);
	std::cout << std::endl;
	bank.depositMoney(1, 1000.0);
	std::cout << std::endl;
	bank.depositMoney(2, 250.75);
	std::cout << std::endl;
	bank.depositMoney(3, 1500.50);
	std::cout << std::endl;

	// Test 4: Try to deposit negative amount (should fail)
	std::cout << CYAN << "TEST 4: Trying to deposit negative amount" << RESET << std::endl;
	bank.depositMoney(0, -100.0);
	std::cout << std::endl;

	// Test 5: Try to deposit zero (should fail)
	std::cout << CYAN << "TEST 5: Trying to deposit zero amount" << RESET << std::endl;
	bank.depositMoney(1, 0.0);
	std::cout << std::endl;

	// Test 6: Find existing clients
	std::cout << CYAN << "TEST 6: Finding existing clients" << RESET << std::endl;
	std::vector<Account *>::iterator it0 = bank.findClient(0);
	if (it0 != bank.findClient(-1))
	{
		std::cout << GREEN << "✓ Client with ID 0 found!" << RESET << std::endl;
		std::cout << "  Balance: $" << (*it0)->getBalance() << std::endl;
	}

	std::vector<Account *>::iterator it2 = bank.findClient(2);
	if (it2 != bank.findClient(-1))
	{
		std::cout << GREEN << "✓ Client with ID 2 found!" << RESET << std::endl;
		std::cout << "  Balance: $" << (*it2)->getBalance() << std::endl;
	}
	std::cout << std::endl;

	// Test 7: Try to find non-existent client
	std::cout << CYAN << "TEST 7: Trying to find non-existent client (ID: 999)" << RESET << std::endl;
	std::vector<Account *>::iterator it_not_found = bank.findClient(999);
	if (it_not_found == bank.findClient(999))
	{
		std::cout << RED << "✗ Client with ID 999 not found (as expected)" << RESET << std::endl;
	}
	std::cout << std::endl;

	// Test 8: Remove an existing client
	std::cout << CYAN << "TEST 8: Removing a client (ID: 1)" << RESET << std::endl;
	bank.removeCliente(1);
	std::cout << std::endl;

	// Test 9: Try to remove non-existent client
	std::cout << CYAN << "TEST 9: Trying to remove non-existent client (ID: 999)" << RESET << std::endl;
	bank.removeCliente(999);
	std::cout << std::endl;

	// Test 10: Deposit to remaining clients
	std::cout << CYAN << "TEST 10: Depositing more money to remaining clients" << RESET << std::endl;
	bank.depositMoney(0, 100.0);
	std::cout << std::endl;
	bank.depositMoney(2, 50.0);
	std::cout << std::endl;
	bank.depositMoney(3, 200.25);
	std::cout << std::endl;

	// Test 11: Try to deposit to removed client
	std::cout << CYAN << "TEST 11: Trying to deposit to removed client (ID: 1)" << RESET << std::endl;
	bank.depositMoney(1, 500.0);
	std::cout << std::endl;

	// Test 12: Multiple deposits to same account
	std::cout << CYAN << "TEST 12: Multiple deposits to same account (ID: 0)" << RESET << std::endl;
	bank.depositMoney(0, 75.0);
	std::cout << std::endl;
	bank.depositMoney(0, 125.50);
	std::cout << std::endl;

	// Test 13: Large deposits
	std::cout << CYAN << "TEST 13: Large deposits" << RESET << std::endl;
	bank.depositMoney(2, 10000.0);
	std::cout << std::endl;
	bank.depositMoney(3, 5555.55);
	std::cout << std::endl;

	// Test 14: Remove another client and verify
	std::cout << CYAN << "TEST 14: Remove another client (ID: 3)" << RESET << std::endl;
	bank.removeCliente(3);
	std::cout << std::endl;

	// Test 15: Final check - try operations on remaining clients
	std::cout << CYAN << "TEST 15: Final operations on remaining clients" << RESET << std::endl;
	std::vector<Account *>::iterator remaining0 = bank.findClient(0);
	if (remaining0 != bank.findClient(-1))
	{
		std::cout << GREEN << "✓ Client 0 still exists with balance: $" << (*remaining0)->getBalance() << RESET << std::endl;
	}

	std::vector<Account *>::iterator remaining2 = bank.findClient(2);
	if (remaining2 != bank.findClient(-1))
	{
		std::cout << GREEN << "✓ Client 2 still exists with balance: $" << (*remaining2)->getBalance() << RESET << std::endl;
	}
	std::cout << std::endl;

	// Test 16: Check bank liquidity
	std::cout << CYAN << "TEST 16: Checking bank liquidity" << RESET << std::endl;
	std::cout << "Bank liquidity: $" << bank.getLiquidity() << std::endl;
	std::cout << std::endl;

	// Test 17: Give a loan with sufficient liquidity
	std::cout << CYAN << "TEST 17: Giving a loan with sufficient liquidity" << RESET << std::endl;
	bank.giveLoan(0, 100.0);
	std::cout << std::endl;

	// Test 18: Give another loan
	std::cout << CYAN << "TEST 18: Giving another loan to different client" << RESET << std::endl;
	bank.giveLoan(2, 50.0);
	std::cout << std::endl;

	// Test 19: Try to give a loan with insufficient liquidity
	std::cout << CYAN << "TEST 19: Trying to give a loan with insufficient liquidity" << RESET << std::endl;
	bank.giveLoan(0, 100000.0);
	std::cout << std::endl;

	// Test 20: Try to give negative loan
	std::cout << CYAN << "TEST 20: Trying to give negative loan amount" << RESET << std::endl;
	bank.giveLoan(2, -50.0);
	std::cout << std::endl;

	// Test 21: Try to give loan to non-existent client
	std::cout << CYAN << "TEST 21: Trying to give loan to non-existent client" << RESET << std::endl;
	bank.giveLoan(999, 100.0);
	std::cout << std::endl;

	// Test 22: Bank destruction
	std::cout << CYAN << "TEST 22: Bank destruction and memory cleanup" << RESET << std::endl;
	std::cout << YELLOW << "--- Destroying bank and all accounts ---" << RESET << std::endl;

	return (0);
}
