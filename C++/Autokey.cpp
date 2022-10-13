#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Enter text : ";
    string str,key;
    getline(cin,str);
    
    cout<<endl<<"Enter key : ";
    getline(cin,key);
    
    if(str.length()<key.length())
    {
        cout<<"Invalid!!"<<endl;
        return 0;
    }
    
    vector<char> s,k,cy,dy;
    for(int i=0;i<str.length();i++)    // text
    {
        str[i] = tolower(str[i]);
        if(str[i]>='a' &&  str[i]<='z')
           s.push_back(str[i]);
    }
    
    for(int i=0;i<key.length();i++)  //key
    {
        key[i] = tolower(key[i]);
        if(key[i]>='a' &&  key[i]<='z')
           k.push_back(key[i]);
        
    }
    
    int i=0;
    while(k.size()<s.size())
    {
        k.push_back(s[i]);
        i++;
    }
    
    cout<<endl<<"Updated Key : ";
    for(int i=0;i<k.size();i++)
       cout<<k[i];
    cout<<endl;
    
    for(int i=0;i<s.size();i++)
    {
        int a = ((s[i]+k[i])-(97*2))%26;
        char ch = a+97;
        cy.push_back(ch);
    }
    
    cout<<"Cipher Text : ";
    for(int i=0;i<cy.size();i++)
      cout<<cy[i];
      
    for(int i=0;i<cy.size();i++)
    {
        int a = cy[i]-k[i];
        if(a<0)
          a = a + 26;
        a = a%26;
        char ch = a+97;
        dy.push_back(ch);
    }
    
    cout<<endl<<"Decrypted Text : ";
    for(int i=0;i<dy.size();i++)
      cout<<dy[i];
    cout<<endl;
    
    return 0;
}