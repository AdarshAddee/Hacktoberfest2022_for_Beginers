#include<iostream.h>  
#include<stdio.h>  
#include<conio.h>  
#include<stdlib.h>  
void main()  
{  
clrscr();  
int opr;  
int num1, num2, x;  
// display different operation of the calculator  
do  
{  
cout << "Select an operation to perform a simple calculation in C++ Calculator"  
     "\n1 = Addition"  
     "\n2 = Subtraction"  
     "\n3 = Multiplication"  
     "\n4 = Division"  
     "\n5 = Square"  
     "\n6 = Exit"  
     "\n \n Make a choice: ";  
     cin >> opr;  
   switch (opr)  
     {  
     // for addition operation in calculator  
     case 1:  
     cout << "You have selected the Addition Operation.";  
     cout << "\n Please enter the two number: \n";  
     cin >> num1 >> num2;  
     x = num1 + num2;  
     cout << "Sum of two number = " << x;  
     break;  
     // for subtraction operation in calculator  
     case 2:  
     cout << "You have selected the Subtraction Operation.";  
     cout << "\n Please enter the two number: \n";  
     cin >> num1 >> num2;  
     x = num1 - num2;  
     cout << "Subtraction of two number = " << x;  
     break;  
     // for multiplication operation in calculator  
     case 3:  
     cout << "You have selected the Multiplication Operation.";  
     cout << "\n Please enter the two number: \n";  
     cin >> num1 >> num2;  
     x = num1 * num2;  
     cout << "Product of two number = " << x;  
     break;  
     // for division operation in calculator  
     case 4:  
     cout << "You have selected the Division Operation.";  
     cout << "\n Please enter the two number; \n";  
     cin >> num1 >> num2;  
     // while loop checks for divisor whether it is zero  
     while ( num2 == 0)  
     {  
     cout << "\n Divisor cannot be zero"  
         "\n Please enter the divisor once again: ";  
         cin >> num2;  
         }  
     x = num1 / num2;  
     cout << "\n Quotient = " << x;  
     break;  
     // to square a number in calculator  
     case 5:  
     cout << "You have selected the Square Operation.";  
      cout << "\n Please enter any number: \n";  
     cin >> num1;  
     x = num1 * num1;  
     cout << "Square is = " << x;  
     break;  
     case 6: exit(0);  // terminate the program  
     break;  
     default: cout << "\n Something went wrong..!!";  
     break;  
     }  
     cout << "\n----------------------------------------- \n";  
     } while(opr != 6);  
     getch();  
     }  
