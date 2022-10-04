// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Github username: UsmannArshad
// Aim: To Participate in HacktoberFest
// Date: 10/04/2022

// start coding
#include <iostream>
using namespace std;

int main()
{
    int x, y;
    cout << "give x:";
    cin >> x;
    cout << "give y:";
    cin >> y;
    int ans = 1;
    for (int i = 0;i < y;i++)
    {
        ans = ans * x;
    }
    cout << ans;
}


// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
