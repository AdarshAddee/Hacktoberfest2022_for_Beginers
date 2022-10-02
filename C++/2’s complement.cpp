//Program to find two's complement of a binary number
#include <iostream>

#define size 6
using namespace std;

int main() {
  char binary[size + 1], one[size + 1], two[size + 1];
  int i, carry = 1, fail = 0;
  cout << " Input a " << size << " bit binary number: ";
  cin >> binary;
  for (i = 0; i < size; i++) {
    if (binary[i] == '1') {
      one[i] = '0';
    } else if (binary[i] == '0') {
      one[i] = '1';
    } else {
      cout << "Error! Input the number of assigned bits." << endl;
      fail = 1;
      break;
    }
  }
  one[size] = '\0';

  for (i = size - 1; i >= 0; i--) {
    if (one[i] == '1' && carry == 1) {
      two[i] = '0';
    } else if (one[i] == '0' && carry == 1) {
      two[i] = '1';
      carry = 0;
    } else {
      two[i] = one[i];
    }
  }
  two[size] = '\0';
  if (fail == 0) {
    cout << " The original binary = " << binary << endl;
    cout << " After ones complement the value = " << one << endl;
    cout << " After twos complement the value = " << two << endl;
  }
}
