#pragma once

#include <iostream>

struct Account {
    friend struct Bank;

    private:
        int _id;
        double _balance;
        static int next_id;
		Account();

    public:
        ~Account();
		int getID();
		double getBalance();
};