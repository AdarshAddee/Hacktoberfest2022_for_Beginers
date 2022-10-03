#include <bits/stdc++.h>  
#define MAXFACTORS 1024 // Let us consider max factors can be 1024  
using namespace std;  
  
typedef struct   
{  
  
    int size;  
    int factor[MAXFACTORS + 1];  
    int exponent[MAXFACTORS + 1];  
  
} FACTORIZATION;  
  
// Function to find the factorization of M and N  
void FindFactorization(int x, FACTORIZATION* factorization)  
{  
    int i, j = 1;  
    int n = x, c = 0;  
    int k = 1;  
    factorization->factor[0] = 1;  
    factorization->exponent[0] = 1;  
  
    for (i = 2; i <= n; i++) {  
        c = 0;  
  
        while (n % i == 0) {  
            c++;  
  
            // factorization->factor[j]=i;  
            n = n / i;  
            // j++;  
        }  
  
        if (c > 0) {  
            factorization->exponent[k] = c;  
            factorization->factor[k] = i;  
            k++;  
        }  
    }  
  
    factorization->size = k - 1;  
}  
  
  
  
// function to find the gcd using Middle School procedure  
int gcdMiddleSchoolProcedure(int m, int n)  
{  
  
    FACTORIZATION mFactorization, nFactorization;  
  
    int r, mi, ni, i, k, x = 1, j;  
  
    // Step 1.  
    FindFactorization(m, &mFactorization);  
  
  
    // Step 2.  
    FindFactorization(n, &nFactorization);  
  
  
    // Steps 3 and 4.  
    // Procedure algorithm for computing the  
    // greatest common divisor.  
    int min;  
    i = 1;  
    j = 1;  
    while (i <= mFactorization.size && j <= nFactorization.size) {  
        if (mFactorization.factor[i] < nFactorization.factor[j])  
            i++;  
  
        else if (nFactorization.factor[j] < mFactorization.factor[i])  
            j++;  
  
        else /* if arr1[i] == arr2[j] */  
        {  
            min = mFactorization.exponent[i] > nFactorization.exponent[j]  
                    ? nFactorization.exponent[j]  
                    : mFactorization.exponent[i];  
  
            x = x * mFactorization.factor[i] * min;  
            i++;  
            j++;  
        }  
    }  
  
    return x;  
}  
  
  
int main()  
  
{  
  
    int m = 36, n = 60;  
    cout << "GCD of " << m << " and " << n << " is "  
        << gcdMiddleSchoolProcedure(m, n);  
  
    return (0);  
} 