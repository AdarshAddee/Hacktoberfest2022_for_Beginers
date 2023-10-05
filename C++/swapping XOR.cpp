#include <iostream>

int main() {
    int a, b;

    std::cout << "Enter the first number (a): ";
    std::cin >> a;

    std::cout << "Enter the second number (b): ";
    std::cin >> b;

    std::cout << "Before swapping:" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    std::cout << "After swapping:" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    return 0;
}
