#include <stdio.h>

float square_Root(float n) 
{ 

   float a = n; 
        float b = 1; 
        double e = 0.000001; 
        while (a - b > e) { 
            a = (a + b) / 2; 
            b = n / a; 
        } 
   return a; 
} 
  
int main(void)
{ 
    int n = 50; 
    printf("Square root of %d is %f", n, square_Root(n)); 
    n = 17; 
    printf("\nSquare root of %d is %f", n, square_Root(n)); 
    return 0;    
}
