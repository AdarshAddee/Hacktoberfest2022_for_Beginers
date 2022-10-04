#include<bits/stdc++.h>
using namespace std;

int main(){
    string word;
    cin>>word;
    int n=word.length();
    int s=0,e=0,res=0;
    map<char,int> charFreq;
    while(e<n){
        char ch1=word[e];
        charFreq[ch1]++;
        while(charFreq[ch1]>1){
            char ch2=word[s];
            charFreq[ch2]--;
            s++;
        }
    res=max(res,e-s+1);
    e++;
    }

    cout<<res;
    return 0;
}
