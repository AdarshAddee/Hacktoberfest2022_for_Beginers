#include <iostream>
using namespace std;

class FiboClass{
public:
    int a, b, c;
    void generate(int);
};

void FiboClass::generate(int n){
    a = 0; b = 1;
    cout << a << " " <<b;
    for(int i=1; i<= n-2; i++){
        c = a + b;
        cout << " " << c;
        a = b;
        b = c;
    }
    cout << endl;
}

int main() {
    cout << "Fibonacci Series" << endl;
    cout << "Enter the nth term of the series to print: ";
    int n;
    cin  >> n;
    FiboClass FiboClass;
    FiboClass.generate(n);
    return 0;
}