#include <iostream>
#include "plorg.h"

plorg::plorg(const char *n, int c)
{
    strcpy(name, n);
    CI = c;
}

void plorg::showplorg() const
{
    using std::cout;
    cout << "Name: " << name;
    cout << "\n Contentment index: " << CI << std::endl;
}
