#include <iostream>
#include "nms10.h"

int main ()
{
    using namespace SALES;
    double arr[4]={111.11, 222.2, 5465.587, 110035};
    double arr2[10]={0.213, 1.22, 5564.111, 5558.22, 99987, 12313.336, 123.3531};
    Sales sss1 = Sales(arr2, 8);
    sss1.showSales();
    Sales sss2;
    sss2.setSales();
    sss2.showSales();

    return 0;
}
