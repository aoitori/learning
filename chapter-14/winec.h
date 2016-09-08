#ifndef WINEC_H_
#define WINEC_H_
#include <string>
#include <valarray>
#include <iostream>

using std::string;
using std::cout;

template <typename T1, typename T2>
class Pair
{
private:
    T1 a;
    T2 b;
public:
    T1 & first(){return a;}
    T2 & second(){return b;}
    T1 first() const {return a;}
    T2 second() const {return b;}
    Pair(const T1 &aval, const T2 &bval):a(aval), b(bval){ }
    Pair(){ }
};
typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;
class Wine
{
private:
    string name;
    int nyear;
    PairArray yearbottle;
public:
    Wine(const char* l, int y, const int yr[], const int bot[])
    :name(l), nyear(y), yearbottle(ArrayInt(yr, y), ArrayInt(bot, y)){}
    Wine(const char* l, int y)
    :name(l), nyear(y), yearbottle(ArrayInt(0,y), ArrayInt(0,y)){}
    void GetBottles();
    string & Label() {return name;}
    int sum() const {return yearbottle.second().sum();}
    void Show() const;
};

void Wine::GetBottles()
{
    using std::cin;
    cout << "Enter " << name << " data for " << nyear << " year(s):\n";
    for (int n = 0; n < nyear; n++)
    {
        cout << "Enter year: ";
        cin >> yearbottle.first()[n];
        cout << "Enter bottles for that year: ";
        cin >> yearbottle.second()[n];
    }
}

void Wine::Show() const
{
    cout << "Wine: " << name << std::endl;
    cout << "\tYear\tBottles\n";
    for (int n = 0; n < nyear; n++)
    cout << "\t" << yearbottle.first()[n] << "\t" << yearbottle.second()[n] << std::endl;
}
#endif // WINEC_H_
