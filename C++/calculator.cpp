// Github username: PRANJALSAXENA23
// Aim: Make calculator without using operators in program
// Date: 20th oct 2022

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll add(ll a,ll b){ 
    if(b==0)return a;
    else return add(a^b,(a&b)<<1);
}
ll sub(ll a,ll b){ 
    if(b==0)return a;
    else return sub(a^b,((~a)&b)<<1);
}

ll mul(ll a,ll b){ 
    if(b<0){
        b=add(~b,1);
        a=add(~a,1);
    }
    ll res=0;
    while(b>0){
        if(b&1)res=add(res,a);
        a<<=1;
        b>>=1;
    }
    return res;
}

ll divide(ll dividend, ll divisor)
{
    
    ll sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
 
     
    dividend = abs(dividend);
    divisor = abs(divisor);
 
    
    ll quotient = 0;
    while (dividend >= divisor) {
        dividend -= divisor;
        ++quotient;
    }
 
    return quotient * sign;
}

int main()
{

    ll p,r;
    cin>>p>>r;

    cout<<"addition of two number "<<add(p,r)<<endl;
    cout<<"subtraction of two number "<<sub(p,r)<<endl;
    cout<<"multiplication of two number "<<mul(p,r)<<endl;
    cout<<"division of two number "<<divide(p,r)<<endl;

}
