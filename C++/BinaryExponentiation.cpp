#include<bits/stdc++.h>
using namespace std;

//calculates a^b in O(log2(b)) time complexity

int power(int base, int exp){
  if(exp==0) return 1;
  if(exp%2==1) return base*power(base,exp-1);
  return power(base*base,exp/2);
}

int main(){
  int base, exp;
  cin>>base>>exp;
  cout<<power(base,exp)<<endl;
}
