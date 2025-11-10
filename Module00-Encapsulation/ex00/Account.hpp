#pragma once

#include <iostream>

struct Account {
    friend struct Bank;

    private:
        int _id;
        float _balance;
        static int next_id;
		Account();

    public:
        ~Account();
};

/*
std::ostream& operator << (std::ostream& p_os, const Account& p_account)
{
    p_os << "ID - [" << p_account.getAccountID() << "]\nValue - [" << p_account.getAccountValue() << "]\n";
    return (p_os);
}
*/

int Account::next_id = 0;