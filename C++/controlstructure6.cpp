#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

void triangle()
{
    int a,b,c;
    cout<<"Enter length of sides of triangle";
    cin>>a>>b>>c;
    if(a==b&&b==c)
        cout<<"\nIt is an equilateral triangle";
    else
        if(a==b||b==c||c==a)
            cout<<"\nIt is an isoceles triangle";
        else
            cout<<"\nIt is a scalene triangle";

}
int main()
{
    triangle();



    return 0;
}