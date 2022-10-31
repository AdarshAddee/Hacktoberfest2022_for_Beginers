#include <iostream>
using namespace std;

int main() 
{
  int no;
  cout << "Enter any number: "; 
  cin >> no;

  if (no % 2 == 0) 
  {
    cout << "The given number is EVEN" << endl;
  } 
  else 
  {
    cout << "The given number is ODD" << endl;
  }

  return 0;
}
