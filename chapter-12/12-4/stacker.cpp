// stacker.cpp -- testing the Stack class
#include <iostream>
#include <cctype>  // or ctype.h
#include "stack.h"
int main()
{
    using namespace std;
    {
    Stack st(0);
    Stack st2(5);
    Stack st3;
    Stack st4(-20);
    char ch;
    unsigned long po;
    Stack choice;
    bool next = false;
    cout << "Please choose a stack (enter 1, 2, 3, 4)\n";
    while (!next && cin >> ch)
    {
        switch (ch)
        {
            case '1': choice = st;
                      next = true;
                      break;
            case '2': choice = st2;
                      next = true;
                      break;
            case '3': choice = st3;
                      next = true;
                      break;
            case '4': choice = st4;
                      next = true;
                      break;
            default : cout << "bad input. Try again.\n";
                      break;
        }
    }
    cout << "Please enter A to add a purchase order,\n"
        << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch(ch)
        {
             case 'A':
             case 'a': cout << "Enter a PO number to add: ";
                       cin >> po;
                       if (choice.isfull())
                           cout << "stack already full\n";
                       else
                           choice.push(po);
                       break;
             case 'P':
             case 'p': if (choice.isempty())
                           cout << "stack already empty\n";
                       else {
                           choice.pop(po);
                           cout << "PO #" << po << " popped\n";
                       }
                       break;
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
    }
    }
    cout << "Bye\n";
    return 0;
}
