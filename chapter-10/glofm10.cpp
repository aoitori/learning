#include <iostream>
#include "10golf.h"

int main ()
{
    golf ann = golf("Ann Birdfree", 24);
    ann.showgolf();
    golf andy[40];
    for (int i = 0; i < 40; ++i)
    {
        if (!andy[i].setgolf(ann))
        {
            std::cout << "\nNo input.Program terminated.\n";
            break;
        }
        andy[i].showgolf();
        andy[i].handget(i);
        andy[i].showgolf();
    }

    return 0;
}
