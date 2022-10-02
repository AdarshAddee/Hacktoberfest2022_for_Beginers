#include<stdio.h>

int main(){
    int n;
    printf("Enter an integer: ");
    scanf("%d",&n);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n-i; ++j){
            printf(" ");
        }
        for(int j=1; j<=((2*i)-1); ++j){
            if(j%2 == 0){
                printf(" ");
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}
