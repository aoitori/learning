#include "list.h"
#include <iostream>
void showlist(Item &x)
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << x << endl;
}

List::List(int n)
{
    using std::cout;
    using std::endl;
    using std::cin;
    int i = 0;
    cout << "Please enter " << n << " items.(q to quit)\n";
    while (i < n)
    {
        index = i++;
        if (!(cin >> items[i]))
            break;

    }

}
void List::addlist(Item &l)
{   if(isfull())
    std::cout << "List is full!!\n";
    else
    items[index++] = l;
}

void List::visit(void (*pf)(Item &))
{
    for (int i = 0; i < index; i++)
        (*pf)(items[i]);
}
