//name-Kartik Soni
//Aim-Creating an efficent algorithm that is order(logn) for calculating fibonacci series
//github username - https://github.com/KartiK-R-Soni


#include <stdio.h>
#define ll long long int

ll Ifib(ll n)
{
    ll ans;
    if(n==0) return 0;
    else if(n==1) return 1;
    else
    {   ll prev=0;
        ans = 1;
        for (ll i = 2; i <= n; i++)
        {
            ll temp = ans;
            ans = (ans + prev) % 2022;
            prev = temp;
        }
    }
    return ans;
}

ll Rfib(ll n)
{
    if (n <= 1)
        return n;
    else
        return (Rfib(n - 1) + Rfib(n - 2)) % 2022;
}

void multiply(int mat[2][2], int m[2][2])
{
    int a = (mat[0][0] * m[0][0] + mat[0][1] * m[1][0]) % 2022;
    int b = (mat[0][0] * m[0][1] + mat[0][1] * m[1][1]) % 2022;
    int c = (mat[1][0] * m[0][0] + mat[1][1] * m[1][0]) % 2022;
    int d = (mat[1][0] * m[0][1] + mat[1][1] * m[1][1]) % 2022;
    mat[0][0] = a;
    mat[0][1] = b;
    mat[1][0] = c;
    mat[1][1] = d;
}

void power(int mat[2][2], ll n)
{
    if (n == 0)
    {
        mat[0][0] = 1;
        mat[0][1] = 0;
        mat[1][0] = 0;
        mat[1][1] = 1;
        return;
    }
    int m[2][2] = {{1, 1}, {1, 0}};
    power(mat, n / 2);
    multiply(mat, mat);
    if (n % 2 == 1)
        multiply(mat, m);
}

ll Cleverfib(ll n)
{
    if (n <= 1)
        return n;
    int mat[2][2] = {{1, 1}, {1, 0}};
    power(mat, n - 1);
    return mat[0][0];
}

int main()
{
    ll n, ans_Rfib,ans_Ifib,ans_Cleverfib;
    scanf("%lld", &n);
    ans_Rfib=Rfib(n);
    ans_Ifib=Ifib(n);
    ans_Cleverfib= Cleverfib(n);
    printf("%lld\n%lld\n%lld\n", ans_Rfib,ans_Ifib,ans_Cleverfib);
    return 0;
}