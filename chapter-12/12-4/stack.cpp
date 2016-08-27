// stack.cpp -- Stack member functions
#include "stack.h"
#include <iostream>
Stack::Stack(int n)    // create an empty stack
{
    if ( n > MAX)
        n = MAX;
    else if (n < 0 && n > -MAX)
        n = -n;
    else if (n < -MAX)
        n = MAX;
    top = size = n;
    pitems = new Item[size];
    for (int i = 0; i < top; i++)
        pitems[i] = i + 1;
}

Stack::Stack(const Stack &st)
{
    delete [] pitems;
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for (int i = 0; i < size; i++)
        pitems[i] = st.pitems[i];
}

Stack::~Stack()
{
    delete [] pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item & item)
{
    if (top < MAX)
    {
        pitems[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = pitems[--top];
        return true;
    }
    else
        return false;
}

Stack & Stack::operator=(const Stack &st)
{
    if (this == &st)
        return *this;

        delete [] pitems;
        size = st.size;
        top = st.top;
        pitems = new Item[size];
    for (int i = 0; i < size; i++)
        pitems[i] = st.pitems[i];
       return *this;
}
