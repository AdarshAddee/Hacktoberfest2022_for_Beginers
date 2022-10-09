#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    int number,guess,nguesses=1;
    srand(time(0));
    number=rand()%100+1;//generate random variable between 1 and 100 
    //printf("The number is %d\n",number);
// keep running the loop until the number is guessed
do{
    printf("guess the number between 1 and 100\n");
    scanf("%d",&guess);
    if(guess>number){
        printf("lower number please!\n");
    }
    else if(guess<number)
    {
        printf("heigher number please!\n");
        
    }
    else{
    printf("you guessed it in %d attemt\n",nguesses);
    }
    nguesses++;


}while(guess!=number);
 return 0;
}
