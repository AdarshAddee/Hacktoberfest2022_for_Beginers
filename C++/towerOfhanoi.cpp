#include<iostream>
using namespace std;

void towerOhHanoi(int n,char a,char b,char c)
{
    if (n==1)
    {
        cout<<"Move 1 from "<<a<<" to "<<c<<endl;//this will take the top dics to auxiliary c tower
        return;
    }
    towerOhHanoi(n-1,a,c,b);//this will take (n-1)th disc to from a to b using c as auxiliary while setting for other number disc too.
    cout<<"Move "<<n<<" from "<<a<<" to "<<c<<endl;//this will move nth dics to required position
    towerOhHanoi(n-1,b,a,c);//this will take (n-1) disc from b to c using a as auxiliary while setting for other number disc too.
}

int main()
{
    towerOhHanoi(3,'A','B','C');
    return 0;
}
