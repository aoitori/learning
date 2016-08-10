#include <iostream>
#include "header.h"

Move::Move(double a, double b)
{
    x = a;
    y = b;
}

void Move::showmove() const
{
    using std::cout;
    using std::endl;
    cout << "Current move: " << x << ", " << y << endl;
}

Move Move::add(const Move &m) const
{
    Move temp = Move((this->x + m.x), (this->y + m.y));
    return temp;
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}
