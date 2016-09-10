#ifndef WINEC2_H_
#define WINEC2_H_
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
class Wine : private string, private PairArray
{
private:
    int nyear;
public:
    Wine(const char* l, int y, const int yr[], const int bot[])
    :string(l), nyear(y), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)){}
    Wine(const char* l, int y)
    :string(l), nyear(y), PairArray(ArrayInt(0,y), ArrayInt(0,y)){}
    void GetBottles();
    string & Label() {return (string &)*this;}
    int sum() const {return PairArray::second().sum();}
    void Show() const;
};

void Wine::GetBottles()
{
    using std::cin;
    cout << "Enter " << (const string)*this << " data for " << nyear << " year(s):\n";
    for (int n = 0; n < nyear; n++)
    {
        cout << "Enter year: ";
        cin >> PairArray::first()[n];
        cout << "Enter bottles for that year: ";
        cin >> PairArray::second()[n];
    }
}

void Wine::Show() const
{
    cout << "Wine: " << (const string)*this << std::endl;
    cout << "\tYear\tBottles\n";
    for (int n = 0; n < nyear; n++)
    cout << "\t" << PairArray::first()[n] << "\t" << PairArray::second()[n] << std::endl;
}
#endif // WINEC_H_
