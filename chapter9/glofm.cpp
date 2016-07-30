#include <iostream>
#include "golf.h"
void setgolf (golf &g, const char* name, int hc);
int setgolf (golf &g);
void handicap (golf &g, int hc);
void showgolf(const golf &g);

int main ()
{
    golf ann;
    setgolf(ann, "Ann Birdfree", 24);
    showgolf(ann);
    handicap(ann, 10);
    showgolf(ann);

    golf andy[Len];
    for (int i = 0; 0 < Len; ++i)
    {
        if (!setgolf(andy[i]))
        {
            std::cout << "\nNo input.Program terminated.\n";
            break;
        }
        showgolf(andy[i]);
        handicap(andy[i], i);
        showgolf(andy[i]);
    }

    return 0;
}
