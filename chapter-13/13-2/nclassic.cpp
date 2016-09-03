#include "classic.h"
#include "iostream"
#include "cstring"
using std::cout;
using std::endl;

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
    performers = new char[(strlen(s1) + 1)];
    label = new char[(strlen(s2) + 1)];
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd &d)
{
    performers = new char[(strlen(d.performers) + 1)];
    label = new char[(strlen(d.label) + 1)];
    strcpy(performers, d.performers);
    strcpy(performers, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    performers = new char[2];
    label = new char[2];
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

void Cd::Report() const
{
    cout << "Performer: " << performers << endl;
    cout << "Label: " << label << endl;
    cout << "Selections: " << selections << endl;
    cout << "Play time: " << playtime << "s.\n\n";
}

Cd& Cd::operator=(const Cd& d)
{
   if (this == &d)
        return *this;
    delete [] performers;
    delete [] label;
    performers = new char[(strlen(d.performers) + 1)];
    label = new char[(strlen(d.label) + 1)];
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

Classic::Classic(const char* s1, const char* s2, const char*s3, int n, double x) : Cd(s1, s2, n, x)
{
    primary = new char [(strlen(s3) +1)];
    strcpy(primary, s3);
}

Classic::Classic(const Classic &c) : Cd(c)
{
    primary = new char [(strlen(c.primary) + 1)];
    strcpy(primary, c.primary);
}

void Classic::Report() const
{
    cout << "Primary: " << primary << endl;
    Cd::Report();
}

Classic& Classic::operator=(const Classic &c)
{
    if (this == &c)
        return *this;
    delete [] primary;
    Cd::operator=(c);
    primary = new char [(strlen(c.primary) + 1)];
    strcpy(primary, c.primary);
    return *this;
}
