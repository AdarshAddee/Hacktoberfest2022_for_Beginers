// Fibonacci Numbers 
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55....

#include <iostream>

using namespace std;

int main()
{
        int n;
        cout << "Enter the value of n : " ;
        cin >> n;
        
        if(n <= 1)
        {
                cout << "The nth Fibonacci Number is  : " << n << endl; 
        }
        else
        {
                // first = 0 and second = 1 are predefined, hence started the loop from the 2nd indexed fibonacci number
                int first = 0, second = 1, sum = 0;
                
                for(int i = 2; i <= n; i++)
                {
                        sum = first + second;
                        first = second;
                        second = sum;
                }
                
                cout << "The nth Fibonacci Number is  : " << second << endl; 
        }
}
