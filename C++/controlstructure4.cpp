#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;

void leapyear(int year)
{
    

    // leap year if perfectly divisible by 400
    if (year % 400 == 0)
    {
        cout << year << " is a leap year.";
    }
    // not a leap year if divisible by 100
    // but not divisible by 400
    else if (year % 100 == 0)
    {
        cout << year << " is not a leap year.";
    }
    // leap year if not divisible by 100
    // but divisible by 4
    else if (year % 4 == 0)
    {
        cout << year << " is a leap year.";
    }
    // all other years are not leap years
    else
    {
        cout << year << " is not a leap year.";
    }
}
int main()
{
    // check whether the year entered by the user is a leap year or not.

    int year;
    cout << "Enter a year: ";
    cin >> year;

    leapyear(year);
    

    return 0;
}
