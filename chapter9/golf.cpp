#include <iostream>
#include <cstring>
#include "golf.h"
void setgolf (golf &g, const char* name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}
int setgolf (golf &g)
{
    using std::cout;
    using std::cin;
    cout << "\nPlease enter your name: ";
    cin.getline(g.fullname, Len);
    if(strcmp(g.fullname, ""))
    {
    cout << "Enter the number of handicap: ";
    cin >> g.handicap;
    cin.get();
    return 1;
    }
    else
        return 0;
}
void handicap (golf &g, int hc)
{
    g.handicap = hc;
}
void showgolf(const golf &g)
{
    std::cout << "Your name: " << g.fullname << "\nYour handicap: " << g.handicap << std::endl;
}
