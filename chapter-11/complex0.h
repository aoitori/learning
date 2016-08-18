#include <string>
#include <iostream>
class complex
{
private:
    double x;
    double y;
    std::string complete = "(";
public:
    complex(double a, double b);
    complex(){ x = y = 0;}
    ~complex() {}
    friend complex operator+ (const complex& a, const complex& b);
    friend complex operator- (const complex& a, const complex& b);
    friend complex operator* (const complex& a, const complex& b);
    friend complex operator* (const double& a, const complex& b);
    friend complex operator~ (const complex& a);
    friend std::ostream& operator<< (std::ostream& os, const complex& n);
    friend std::istream& operator>> (std::istream& is, complex& n);
};
