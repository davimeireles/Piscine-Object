#pragma once

#include <iostream>
#include <vector>
#include "Account.hpp"

struct Bank {

    private:
	    int liquidity;
	    std::vector<Account *> clientAccounts;

    public:
	    Bank() : liquidity(0) {}
        ~Bank() {}
        std::vector<Account *> getClientAccounts() const { return this->clientAccounts; }
        int getBankLiquidity() const { return this->liquidity; }
        void setBankLiquidity(int liquidity) { this->liquidity = liquidity; }
        void addNewClientAccount(Account *newAccount) { this->clientAccounts.push_back(newAccount); }
};

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
    p_os << "Bank informations : " << std::endl;
    p_os << "Liquidity : " << p_bank.getBankLiquidity() << std::endl;
    return (p_os);
}