//https://leetcode.com/problems/reverse-integer/

#include <bits/stdc++.h>
using namespace std;

    int reverse(int x) {
        long int reverse=0;
        while(x!=0){
            int digit=x%10;
            reverse=reverse*10+ digit;
            x=x/10;
        }
        return reverse; }
int main(){
  int x=2487;
  cout<<"Reverse no : "<<reverse(x);
  return 0; }

    
