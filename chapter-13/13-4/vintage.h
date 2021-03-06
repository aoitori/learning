#ifndef VINTAGE_H
#define VINTAGE_H
#include "Port.h"
class VintagePort : public Port
{
private:
    char* nickname;
    int year;
public:
    VintagePort();
    VintagePort(const char* br, int b, const char* nn, int y);
    VintagePort(const VintagePort &vp);
    ~VintagePort(){delete [] nickname;}
    VintagePort & operator=(const VintagePort &vp);
    void Show() const;
    friend std::ostream & operator<<(std::ostream & os,
                                     const VintagePort &vp);
};
#endif // VINTAGE_H
