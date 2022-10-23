#include<iostream>
using namespace std;
 
int main(){
    int i,j,temp;
    char string[80]={"OOP is important subject"};
    char substring[78]={"important"};
 
    for(i=0;string[i]!='\0';i++)
    {
        j=0;
        if(string[i]==substring[j])
        {
            temp=i+1;
            while(string[i]==substring[j])
            {
                i++;
                j++;
            }
 
            if(substring[j]=='\0')
            {
                cout<<"The substring is present in given string at position "<<temp<<"\n";
                exit(0);
            }
            else
            {
                i=temp;
                temp=0;
            }
        }
    }
    if(temp==0)
        cout<<"The substring is not present in given string\n";
 
    return 0;
}
