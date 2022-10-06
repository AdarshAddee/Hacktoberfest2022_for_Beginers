#include<iostream>
using namespace std;

int fact(int n)
{
    int factorial=1;
    for(int i=n;i>=1;i--)
    factorial=factorial*i;
    return factorial;
}
int main(){
    int n;
    printf("enter the number ");
    scanf("%d",&n);
    printf("the factorial of the number is %d",fact(n));
    
}
