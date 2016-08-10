#include "header.h"

int main ()
{
    Move n {123133.22, 55};
    Move m = Move(50, 40.12);
    n.add(m).showmove();
    n.showmove();
    n.reset();
    n.showmove();

    return 0;
}
