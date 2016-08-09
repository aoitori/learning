#include <iostream>
#include "nms10.h"
#include <cctype>
namespace SALES
{
    using std::cout;
    using std::cin;
    using std::endl;
    Sales::Sales (const double ar[], int n)
    {
        double sum = 0.0;
        for (int i = 0; i <  QUARTERS; i++)
        {
            if (i < n)
                sales[i] = ar[i];
            else
                sales[i] = 0;
            sum += sales[i];
        }
        average = sum / QUARTERS;
        double t1, t2;
        t1 = t2 = sales[0];
        for (int j = 1; j < QUARTERS; j++)
        {
            t1 = t1 < sales[j] ? t1 : sales[j];
            t2 = t2 > sales[j] ? t2 : sales[j];
        }
        Max = t1;
        Min = t2;
    }

    void Sales::setSales ()
    {
        double sum = 0.0;
        cout << "Please enter 4 quarters sales ";
        for (int i = 0; i < QUARTERS; i++)
        {
            cout << "#" << i+1 << ": ";
            cin >> this->sales[i];
            sum += this->sales[i];
        }
        this->average = sum / QUARTERS;
        double t1, t2;
        t1 = t2 = this->sales[0];
        for (int j = 1; j < QUARTERS; j++)
        {
            t1 = t1 < this->sales[j] ? t1 : this->sales[j];
            t2 = t2 > this->sales[j] ? t2 : this->sales[j];
        }
        this->Max = t1;
        this->Min = t2;
    }

    void Sales::showSales () const
    {
        cout << "4 quarters sales" << endl;
        for (int i = 0; i < QUARTERS; i++)
            cout << "#" << i+1 << ": " << sales[i] << endl;
        cout << "Average: " << average << endl;
        cout << "Max: " << Max << endl;
        cout << "Min: " << Min << endl;
    }
}
