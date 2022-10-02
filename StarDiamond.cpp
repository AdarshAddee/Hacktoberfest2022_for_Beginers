#include <iostream>
using namespace std;
int main()
{
int n, s, x, y;
cout << "Enter number of rows to show star pattern: ";
cin >> n;
for(x = 0; x <= n; x++)
{
for(s = n; s > x; s--)
cout << " ";
for(y = 0; y < x; y++)
cout << "* ";
cout << "\n";
}
for(x = 1; x < n; x++)
{
for(s = 0; s < x; s++)
cout << " ";
for(y = n; y > x;  y--)
cout << "* ";
cout << "\n";
}
return 0;
}
