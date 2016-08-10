#include "plorg.h"

int main ()
{
    plorg a;
    plorg b{"Iceman", 555};
    plorg c = plorg("aaa", 888);
    a.showplorg();
    a.change(999);
    b.change(1);
    b.showplorg();
    c.showplorg();
    a.showplorg();

    return 0;
}
