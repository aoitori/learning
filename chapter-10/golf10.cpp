#include <iostream>
#include <cstring>
#include "10golf.h"

golf::golf (const char* fn, int s)
{
    strcpy(fullname, fn);
    handicap = s;
}

int golf::setgolf (golf &g)
{
    char fullname[40];
    int hd;
    using std::cout;
    using std::cin;
    cout << "\nPlease enter your name: ";
    cin.getline(fullname, 40);
    if(strcmp(fullname, ""))
    {
    cout << "Enter the number of handicap: ";
    cin >> hd;
    cin.get();
    g = golf(fullname, hd);
    *this = g;
    return 1;
    }
    else
        return 0;
}
void golf::handget (const int hc)
{
    handicap += hc;
}
void golf::showgolf() const
{
    std::cout << "Your name: " << fullname << "\nYour handicap: " << handicap << std::endl;
}
