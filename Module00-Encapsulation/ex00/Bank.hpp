#pragma once

#include <iostream>
#include <vector>
#include "Account.hpp"

struct Bank {

    private:
	    int _liquidity;
	    std::vector<Account *> _clients;

    public:
	    Bank();
        ~Bank();
		void addNewClient(float balance);
};

/*
std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
    p_os << "Bank informations : " << std::endl;
    p_os << "Liquidity : " << p_bank.getBankLiquidity() << std::endl;
    return (p_os);
}
	*/