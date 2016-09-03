#ifndef CLASSIC_H
#define CLASSIC_H
#include "Cd.h"

class Classic : public Cd
{
private:
    char primary[50];
public:
    Classic(const char* s1 = "none", const char* s2 = "none" ,const char *s3 = "none", int n = 0, double x = 0);
    Classic(const Classic &c);
    ~Classic(){};
    void Report() const;
    Classic& operator=(const Classic &c);
};

#endif // CLASSIC_H
