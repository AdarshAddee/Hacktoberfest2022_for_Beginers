// Temperature Conversion Celsius To Fahrenheit And Vice Versa.
#include<iostream>
#include<iomanip>
using namespace std;
int celsi(long a){
    long t;
    t=(a - 32.0) * 5.0 / 9.0;
    return t;
}
int fahren(long a){
    long t;
    t=(a*9/5)+32;
    return t;
}

int main(){
    long temp;
    cout<<"enter the temp:";
    cin>>temp;
    int l;
    cout<<"type 1 to convert to celsius"<<endl;
    cout<<"type 2 to convert to fahrenheit"<<endl;
    cin>>l;
    switch(l){
        case 1:
        cout<<setprecision(6)<<celsi(temp);
        break;
        case 2:
        cout<<setprecision(6)<<fahren(temp);
        break;
        default:
        cout<<"enter proper choice";
        break;
    }
    return 0;
}