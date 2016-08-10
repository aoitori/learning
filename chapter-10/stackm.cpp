#include "Stack.h"
#include <iostream>
int main ()
{
    using namespace std;
    Item a[10] {{"11111", 22222.2456}, {"secod", 589.21}, {"therd", .213},
                {"fooue", 1564.00005}, {"fiv", 879333.2}, {"6fksq", 123132},
                {"seven", 777777}, {"eeee", 0000.0007}, {"nnn", 9909.9}, {"", 0}};
    Stack x;
    for (int i = 0; i < 10; i++)
    x.push(a[i]);
    cout << x.isfull() << endl << x.isempty() << endl;
    x.pop(a[9]);
    x.pop(a[8]);
    x.pop(a[7]);
    x.pop(a[6]);
    return 0;
}
