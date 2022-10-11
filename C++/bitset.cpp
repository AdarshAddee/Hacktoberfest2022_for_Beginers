/ C++ program to demonstrate various functionality of bitset
#include <bits/stdc++.h>
using namespace std;
  
#define M 32
  
int main()
{
    // default constructor initializes with all bits 0
    bitset<M> bset1;
  
    // bset2 is initialized with bits of 20
    bitset<M> bset2(20);
  
    // bset3 is initialized with bits of specified binary string
    bitset<M> bset3(string("1100"));
  
    // cout prints exact bits representation of bitset
    cout << bset1 << endl; // 00000000000000000000000000000000
    cout << bset2 << endl; // 00000000000000000000000000010100
    cout << bset3 << endl; // 00000000000000000000000000001100
    cout << endl;
  
    // declaring set8 with capacity of 8 bits
  
    bitset<8> set8; // 00000000
  
    // setting first bit (or 6th index)
    set8[1] = 1; // 00000010
    set8[4] = set8[1]; // 00010010
    cout << set8 << endl;
  
    // count function returns number of set bits in bitset
    int numberof1 = set8.count();
  
    // size function returns total number of bits in bitset
    // so there difference will give us number of unset(0)
    // bits in bitset
    int numberof0 = set8.size() - numberof1;
  
    cout << set8 << " has " << numberof1 << " ones and "
         << numberof0 << " zeros\n";
  
    // test function return 1 if bit is set else returns 0
    cout << "bool representation of " << set8 << " : ";
    for (int i = 0; i < set8.size(); i++)
        cout << set8.test(i) << " ";
  
    cout << endl;
  
    // any function returns true, if atleast 1 bit
    // is set
    if (!set8.any())
        cout << "set8 has no bit set.\n";
  
    if (!bset1.any())
        cout << "bset1 has no bit set.\n";
  
    // none function returns true, if none of the bit
    // is set
    if (!bset1.none())
        cout << "bset1 has some bit set\n";
  
    // bset.set() sets all bits
    cout << set8.set() << endl;
  
    // bset.set(pos, b) makes bset[pos] = b
    cout << set8.set(4, 0) << endl;
  
    // bset.set(pos) makes bset[pos] = 1  i.e. default
    // is 1
    cout << set8.set(4) << endl;
  
    // reset function makes all bits 0
    cout << set8.reset(2) << endl;
    cout << set8.reset() << endl;
  
    // flip function flips all bits i.e.  1 <-> 0
    // and  0 <-> 1
    cout << set8.flip(2) << endl;
    cout << set8.flip() << endl;
  
    // Converting decimal number to binary by using bitset
    int num = 100;
    cout << "\nDecimal number: " << num
         << "  Binary equivalent: " << bitset<8>(num);
  
    return 0;
}
