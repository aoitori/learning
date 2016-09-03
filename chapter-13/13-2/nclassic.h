#ifndef CLASSIC_H
#define CLASSIC_H
#include "Cd.h"

class Classic : public Cd
{
private:
    char* primary;
public:
    Classic(const char* s1 = "", const char* s2 = "" ,const char *s3 = "", int n = 0, double x = 0);
    Classic(const Classic &c);
    ~Classic(){delete []primary;}
    void Report() const;
    Classic& operator=(const Classic &c);
};

#endif // CLASSIC_H
