#pragma once

#include <iostream>

struct Account {

    private:
        int id;
        int value;
        static int next_id;

    public:
        Account() : id(next_id++), value(0) {}
        ~Account() {}
        int getAccountID() const { return this->id; }
        int getAccountValue() const { return this->value; }
};

std::ostream& operator << (std::ostream& p_os, const Account& p_account)
{
    p_os << "ID - [" << p_account.getAccountID() << "]\nValue - [" << p_account.getAccountValue() << "]\n";
    return (p_os);
}

int Account::next_id = 0;