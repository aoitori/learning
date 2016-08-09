#include <iostream>
#include "10-2.h"

int main ()
{
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    two.Show();
    std::cout << std::endl;
    two.FormalShow();
    three.Show();
    std::cout << std::endl;
    three.FormalShow();
    one = Person("one", "First");
    one.Show();
    one.FormalShow();

    return 0;
}
