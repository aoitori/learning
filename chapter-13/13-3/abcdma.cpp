// dma.cpp --dma class methods

#include "abcdma.h"
#include <cstring>
using namespace std;
// baseDMA methods
defDMA::defDMA(const char * l, int r)
{
    label = new char[strlen(l) + 1];
    strcpy(label, l);
    rating = r;
}

defDMA::defDMA(const defDMA & rs)
{
    label = new char[strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating;
}


defDMA & defDMA::operator=(const defDMA & rs)
{
    if (this == &rs)
        return *this;
    delete [] label;
    label = new char[strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}



//base methods
baseDMA::baseDMA(const char* l, const char* f, int r): defDMA(l,r)
{
    food = new char [(strlen(f) + 1)];
    strcpy(food, f);
}

baseDMA::baseDMA(const baseDMA &rs): defDMA(rs)
{
    food = new char [(strlen(rs.food) + 1)];
    strcpy(food, rs.food);
}

void baseDMA::View() const
{
    cout << "invoke base\n";
    cout << "Label: " << rlabel() << "\nRate: "
         << rate() << endl;
    cout << "Food: " << food << endl;
}

baseDMA& baseDMA::operator=(const baseDMA& rs)
{
    if (this == &rs)
        return *this;
    defDMA::operator=(rs);
    delete [] food;
    food = new char [(strlen(rs.food) + 1)];
    strcpy(food, rs.food);
    return *this;
}
//lacksDMA methods
lacksDMA::lacksDMA(const char* c, const char* l, int r)
: defDMA(l, r)
{
    strncpy(color, c, COL_LEN - 1);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char* c, const defDMA &rs)
: defDMA(rs)
{
    strncpy(color, c, COL_LEN - 1);
    color[39] = '\0';
}

void lacksDMA::View() const
{
    cout << "invoke lacks\n";
    cout << "Label: " << rlabel() << "\nRate: "
         << rate() << endl;
    cout << "Color: " << color << endl;
}
// hasDMA methods
hasDMA::hasDMA(const char * s, const char * l, int r): defDMA(l, r)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const defDMA & rs)
         : defDMA(rs)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs)
         : defDMA(hs)  // invoke base class copy constructor
{
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

void hasDMA::View() const
{
    cout << "invoke has\n";
    cout << "Label: " << rlabel() << "\nRate: "
         << rate() << endl;
    cout << "Style: " << style << endl;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
        return *this;
    defDMA::operator=(hs);  // copy base portion
    delete [] style;         // prepare for new style
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
    return *this;
}

