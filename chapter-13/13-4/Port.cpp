#include "vintage.h"
#include <cstring>
using namespace std;

Port::Port(const char* br, int b, const char* st)
{
    brand = new char [(strlen(br)+1)];
    strcpy(brand, br);
    bottles = b;
    strncpy(style, st, 19);
    style[19] = '\0';
}

Port::Port(const Port &p)
{
    brand = new char [(strlen(p.brand)+1)];
    strcpy(brand, p.brand);
    bottles = p.bottles;
    strncpy(style, p.style, 19);
    style[19] = '\0';
}

Port & Port::operator=(const Port &p)
{
    if(this == &p)
        return *this;
    delete [] brand;
    brand = new char [(strlen(p.brand)+1)];
    strcpy(brand, p.brand);
    bottles = p.bottles;
    strncpy(style, p.style, 19);
    style[19] = '\0';
    return *this;
}

Port & Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b)
{
    if (bottles < b)
        cout << "You haven't such more bottles.\n";
    else
        bottles -= b;
    return *this;
}

void Port::Show() const
{
    cout << "Brand: " << brand << endl
         << "Style: " << style << endl
         << "Bottles: " << bottles << endl;
}

ostream & operator<< (ostream &os, const Port &p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles
       << " ";
       return os;
}

VintagePort::VintagePort(): Port()
{
    nickname = new char [1];
    nickname[0] = '\0';
    year = 0;
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y)
: Port(br, b)
{
    nickname = new char [(strlen(nn)+1)];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort &vp)
: Port(vp)
{
    nickname = new char [(strlen(vp.nickname)+1)];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort &vp)
{
    if (this == &vp)
        return *this;
    Port::operator=(vp);
    delete [] nickname;
    nickname = new char [(strlen(vp.nickname)+1)];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    cout << "Nickname: " << nickname << endl
         << "Year: " << year << endl;
}

ostream & operator<<(ostream &os, const VintagePort &vp)
{
    os << (const Port &)vp;
    os << "\n" << vp.nickname << ", " << vp.year;
    return os;
}
