#include <iostream>
using namespace std;

class Factorial
{
private:
    int num;
    int factorial = 1;

public:
    void calculateFactorial();
    void show();
};

void
Factorial::calculateFactorial()
{
    printf("Enter a number : \n" );
    scanf("%d",&num);

    if (num == 0 || num == 1)
    {
        factorial = 1;
    }
    else
    {
        while (num > 1)
        {
            factorial = factorial * num;
            num--;
        }
    }
}

void Factorial::show()
{
    printf("Factorial : %d\n", factorial);
}

int main()
{
    Factorial factorial;
    factorial.calculateFactorial();
    factorial.show();
}
