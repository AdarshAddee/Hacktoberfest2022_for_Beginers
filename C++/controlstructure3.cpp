#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    //check whether an alphabet entered by the user is a vowel or a consonant.
    char c;
    cout<<"\n Enter an letter ";
    cin>>c;
    if(c=='A'||c=='a'||c=='E'||c=='e'||c=='I'||c=='i'||c=='O'||c=='o'||c=='U'||c=='u')
        cout<<"\n It is a vowel. ";
    else
        cout<<"\n It is a consonant. ";
    


    return 0;
}



