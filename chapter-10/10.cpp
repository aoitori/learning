#include <iostream>
#include "10.h"


BankAccount::BankAccount()
{
    name = "";
    acctnum = "";
    balance = 0.0;
}

BankAccount::~BankAccount()
{

}

BankAccount::BankAccount(const string &client, const string &num, double bal)
{
        name = client;
        acctnum = num;
        balance = bal;
}
    void BankAccount::show(void) const
    {
        using std::cout;
        using std::endl;
        cout << "Your name: " << name << endl;
        cout << "Balance: " << acctnum << endl
             << balance << endl;
    }
    void BankAccount::deposit (double cash)
    {
        if (cash < 0)
            std::cout << "Bad request!!!" << std::endl;
        else
            balance += cash;
    }
    void BankAccount::withdraw (double cash)
    {
        using std::cout;
        using std::endl;
        if (cash > balance)
            cout << "Your balance is " << balance << ".\nCouldn't take "
                 << cash << "out.\n";
        else
            balance -= cash;
    }

