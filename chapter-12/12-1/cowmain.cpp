#include "cow.h"
#include <iostream>
int main ()
{
    using std::cout;

    Cow a;
    Cow b("Aoi Tori", "travle, shotting", 50);
    Cow c = b;
    cout << "initially a:\n";
    a.ShowCow();
    cout << "b:\n";
    b.ShowCow();
    cout << "c:\n";
    c.ShowCow();
    a = Cow(c);
    cout << "After a:\n";
    a.ShowCow();
    return 0;
}
