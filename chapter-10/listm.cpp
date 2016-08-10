#include "list.h"
#include <iostream>
int main ()
{
    List a = List(15);
    Item test[22]{123.1233, 456.46, 789.789};
    a.addlist(test[0]);
    a.visit(showlist);
    return 0;
}
