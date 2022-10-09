#include<iostream>
#include<conio.h>
using namespace std;

int main()
{

    // Write a program to calculate the total salary of a person.
    // The user has to enter the basic salary (an integer) and the grade (an uppercase character),
    // and depending upon which the total salary is calculated as -    
    //  totalSalary = basic + hra + da + allow – pf. 
    //where : hra = 20% of basic, da = 50% of basic, allow = 1700 if grade = ‘A’, 
    //allow = 1500 if grade = ‘B’, allow = 1300 if grade = ‘C' or any other character, pf = 11% of basic. 
    //Round off the total salary and then print the integral part only.
    int basic,totalsalary;
    char grade;
    float hra,da,allow,pf;

    cout<<"\n Enter basic salary : ";
    cin>>basic;
    cout<<"\n Enter grade : ";
    cin>>grade;

    hra=0.2*basic;
    da=0.5*basic;
    pf=0.11*basic;
    if(grade=='A')
        allow=1700;
    else
        if(grade=='B')
            allow=1500;
        else
            allow=1300;
    
    totalsalary = basic + hra + da + allow - pf;

    cout<<"\n Your total salary is : "<<totalsalary;

    return 0;
}