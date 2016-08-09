#include <iostream>
#include "10-2.h"
#include <cstring>
using std::cout;
using std::endl;
Person::Person(const string &ln, const char *fn)
{
    lname = ln;
    strcpy(fname, fn);
}
void Person::Show() const
{
    cout << "Your name: " << fname << " " << lname << endl;
}
void Person::FormalShow() const
{
    cout << "Formal name: " << lname << " " << fname << endl;
}
