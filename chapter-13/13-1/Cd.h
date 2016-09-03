#ifndef CD_H
#define CD_H

class Cd
{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;
public:
    Cd(const char* s1, const char* s2, int n, double x);
    Cd(const Cd &d);
    Cd();
    virtual ~Cd(){};
    virtual void Report() const;
    virtual Cd& operator=(const Cd& d);
};
#endif // CD_H
