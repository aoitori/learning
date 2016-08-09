#include <iostream>
#include "10.h"

int main ()
{
    BankAccount one{"Fist one", "Three hundre", 300};
    BankAccount two = BankAccount("Second two", "zero");
    BankAccount three = BankAccount();
    one.show();
    one.deposit(500);
    two.show();

    three = BankAccount("one million", "one million", 100000);
    three.show();
    three.withdraw(7852);
    three.show();
    one.show();
    return 0;
}
