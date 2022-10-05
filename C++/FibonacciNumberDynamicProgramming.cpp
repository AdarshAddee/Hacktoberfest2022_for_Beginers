#include <iostream>

int FibonacciNumber(int n){
    int f[n + 2];
    f[0] = 0;
    f[1] = 1;

    if(n == 0 || n == 1){
        return f[n];
    }

    for(int i = 2; i < n; i++){
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n] + f[n-1];
}

int main(){
    printf("%d", FibonacciNumber(5));
    return 0;
}