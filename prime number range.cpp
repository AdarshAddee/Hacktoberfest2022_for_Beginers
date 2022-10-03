#include <iostream>
using namespace std;

int main() {

  int l, h;
  bool is_prime = true;

  cout << "Enter two numbers (intervals): ";
  cin >> l>>h;

  cout << "\nPrime numbers between " << l<< " and " << h << " are: " << endl;

  while (l< h) {
    is_prime = true;
    if (l == 0 || l == 1) {
      is_prime = false;
    }
 
    for ( int i = 2; i <= l/2; ++i) {
      if (l % i == 0) {
        is_prime = false;
        break;
      }
    }
        
    if (is_prime)
      cout << l << ", ";

    ++l;
  }

  return 0;
}
