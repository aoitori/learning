#include "abcdma.h"
#include <cctype>
const int CLIENTS = 4;

int main()
{
   using std::cin;
   using std::cout;
   using std::endl;

 {
   defDMA* p_clients[CLIENTS];
   char temp[81];
   char tempchar[81];
   int temprate;
   char kind;

   for (int i = 0; i < CLIENTS; i++)
   {
       cout << "Enter client's label: ";
       cin.getline(temp, 81);
       cout << "Enter client's rating: ";
       while (!(cin >> temprate))
       {
           cin.clear();
           while(cin.get() != '\n')
            continue;
           cout << "Enter again: ";
       }

       cout << "Enter 1 for baseDMA, "
            << "2 for lacksDMA or "
            << "3 for hasDMA: ";
       while ((cin >> kind) && (kind != '1' && kind != '2' && kind != '3'))
           cout <<"Enter either 1, 2, 3 : ";
            while(cin.get() != '\n')
            continue;
       if (kind == '1')
       {
           cout << "Enter the food's name: ";
           cin.getline(tempchar, 81);
           p_clients[i] = new baseDMA(temp, tempchar, temprate);
       }
       else if (kind == '2')
       {
          cout << "Enter color: ";
          cin.getline(tempchar, 81);
          p_clients[i] = new lacksDMA(tempchar, temp, temprate);
        }
        else
        {
            cout << "Enter style: ";
            cin.getline(tempchar, 81);
            p_clients[i] = new hasDMA(tempchar, temp, temprate);
        }

   }
   cout << endl;
   for (int i = 0; i < CLIENTS; i++)
   {
       p_clients[i]->View();
       cout << endl;
   }
    baseDMA test1{"oh my god", "nood", 2};
    test1.View();
    hasDMA test2 = hasDMA("gg", test1);
    test2.View();
    lacksDMA test3("zz", test2);
    test3.View();
   for (int i = 0; i < CLIENTS; i++)
   {
       delete p_clients[i];  // free memory
   }
}
   cout << "Done.\n";
 /* code to keep window open
   if (!cin)
      cin.clear();
   while (cin.get() != '\n')
      continue;
*/
   return 0;
}
