#include "complex0.h"
#include <cstring>
complex::complex(double a, double b)
{
    x = a;
    y = b;
}

complex operator+ (const complex& a, const complex& b)
{
    return complex((a.x + b.x), (a.y + b.y));
}

complex operator- (const complex& a, const complex& b)
{
    return complex((a.x - b.x), (a.y - b.y));
}

complex operator* (const complex& a, const complex& b)
{
    return complex((a.x * b.x - a.y * b.y), (a.x * b.y + a.y * b.x));
}

complex operator* (const double& a, const complex& b)
{
    return complex((a * b.x), (a * b.y));
}

complex operator~ (const complex& a)
{
    return complex(a.x, -a.y);
}

std::ostream& operator<< (std::ostream& os, const complex& n)
{
    os << "(" << n.x << ", " << n.y << "i)";
    return os;
}

std::istream& operator>> (std::istream& is, complex& n)
{
    double i, j;
    std::cout << "real: ";
    if (is >> i)
    {
        std::cout << "imaginary: ";
        is >> j;
        n = complex(i, j);
    }
    return is;
}
