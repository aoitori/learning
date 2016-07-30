#include <iostream>
#include "nms.h"
#include <cctype>
namespace SALES
{
    using std::cout;
    using std::cin;
    using std::endl;
    void setSales (Sales &s, const double ar[], int n)
    {
        double sum = 0.0;
        for (int i = 0; i <  QUARTERS; i++)
        {
            if (i < n)
                s.sales[i] = ar[i];
            else
                s.sales[i] = 0;
            sum += s.sales[i];
        }
        s.average = sum / QUARTERS;
        double t1, t2;
        t1 = t2 = s.sales[0];
        for (int j = 1; j < QUARTERS; j++)
        {
            t1 = t1 < s.sales[j] ? t1 : s.sales[j];
            t2 = t2 > s.sales[j] ? t2 : s.sales[j];
        }
        s.max = t1;
        s.min = t2;
    }

    void setSales (Sales &s)
    {
        double sum = 0.0;
        cout << "Please enter 4 quarters sales ";
        for (int i = 0; i < QUARTERS; i++)
        {
            cout << "#" << i+1 << ": ";
            cin >> s.sales[i];
            sum += s.sales[i];
        }
        s.average = sum / QUARTERS;
        double t1, t2;
        t1 = t2 = s.sales[0];
        for (int j = 1; j < QUARTERS; j++)
        {
            t1 = t1 < s.sales[j] ? t1 : s.sales[j];
            t2 = t2 > s.sales[j] ? t2 : s.sales[j];
        }
        s.max = t1;
        s.min = t2;
    }

    void showSales (const Sales &s)
    {
        cout << "4 quarters sales" << endl;
        for (int i = 0; i < QUARTERS; i++)
            cout << "#" << i+1 << ": " << s.sales[i] << endl;
        cout << "Average: " << s.average << endl;
        cout << "Max: " << s.max << endl;
        cout << "Min: " << s.min << endl;
    }
}
