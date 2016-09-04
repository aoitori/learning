#include "vintage.h"
using namespace std;
int main (void)
{
    Port po1;
    Port po2("fivechild", 20, "cold");
    VintagePort vin1("goodc", 50, "haha", 1995);
    VintagePort vin2;
    cout << "Copy vin1 to po1: " << endl;
    po1 = Port(vin1);
    po1.Show();
    cout << endl;
    cout << po1;
    cout << "\n\ncout vin1\n";
    cout << vin1;
    cout << "\nAssign vin1 to vin2:" << endl;
    vin2 = vin1;
    vin2.Show();
    cout << "\n\nvin2 bottles substract 40:";
    vin2 -= 40;
    cout << vin2;
    cout << "\n\npo1 plus 100 bottles: ";
    po1 += 100;
    cout << po1;
    //cin.get();
    return 0;
}
