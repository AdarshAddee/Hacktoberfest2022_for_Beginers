//insertion of a element in a array
#include <bits/stdc++.h>
#include <vector>
using namespace std;
void main()
{
  vector <int> ar{5,10,20};
  auto it=ar.begin()+1;
  auto iter=ar.insert(it,6);
  for(int i=0;i<ar.size();i++)
  {
    cout<<ar[i]<<" ";
  }
}
