#include <iostream>
using namespace std;

int main()

{
int amount;
   cout << "Enter the amount";
   cin >> amount;
   int RS100, RS20, RS10, RS1;

   switch (1)
   {
   case 1:
      RS100 = amount / 100;
      amount = amount % 100;
      cout << "Enter the number of Required notes 100 =" << RS100;

      case 3:
      RS20 = amount / 20;
      amount = amount % 20;
      cout << "No of 20 Rupee notes required are=" << RS20 << endl;

   case 4:
      RS10 = amount / 10;
      amount = amount % 10;
      cout << "No of 1 Rupee notes required are=" << RS10 << endl;
   }
}
