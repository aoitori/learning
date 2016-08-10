#include "Stack.h"
#include <iostream>

Stack::Stack()
{
    top = 0;
}

void Stack::total()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    runTotal += items[top].payment;
    cout << "running total: " << runTotal << endl;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item &item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item &item)
{
    if (top > 0)
    {
        item = items[--top];
        total();
        return true;
    }
    else
        return false;
}


