// Github username: Harshit0009
// Aim: It will separate same characters in the string with *
// Date: 08-october-2022
// start coding

#include <bits/stdc++.h>
using namespace std;

void pairStar(char input[]) {
    
    int len = 0;
    while (input[len])
        len++;
    if(len <= 1)
        return;
    pairStar(input+1);
    if(input[0]==input[1]){
        for(int i=2*len; i>=1; i--)
            input[i+1]=input[i];
        input[1]='*';
    }    
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}