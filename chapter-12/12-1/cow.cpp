#include <iostream>
#include "cow.h"
#include <cstring>
Cow::Cow()
{
    name[0] = '\0';
    hobby = nullptr;
    weight = 0.0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
    strcpy(name, nm);
    hobby = new char[(strlen(ho) + 1)];
   strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow &c)
{
    strcpy(name, c.name);
    hobby = new char[(strlen(c.hobby) + 1)];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow()
{
    delete [] hobby;
}

Cow& Cow::operator=(const Cow &c)
{
    delete [] hobby;
    if (this->name == c.name)
        return *this;
    else
    {
        strcpy(name, c.name);
        hobby = new char[(strlen(c.hobby) + 1)];
        strcpy(hobby, c.hobby);
        weight = c.weight;
        return *this;
    }
}

void Cow::ShowCow() const
{
    using std::cout;
    using std::endl;

    cout << "Your name is " << name << endl;
    if (hobby)
        cout << "Your hobby is " << hobby << endl;
    else
        cout << "No hobby.\n";
    cout << "Your weight is " << weight << endl;

}
