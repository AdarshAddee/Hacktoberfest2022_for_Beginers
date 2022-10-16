#include<stdio.h>

void swap(int *b,int*c)

{

int temp;

temp=*c;

*c=*b;

*b=temp;

}

int main()

{

int i,j,n,cmpt;

float twt=0,ttat=0;

printf("Enter number of processes:");

scanf("%d",&n);

int a[n][6];

printf("Enter arrival time,bust time,priority of each process:\n");

for(i=0;i<n;i++)

{

printf("Process ID :");

scanf("%d",&a[i][0]);

printf("A.T of process %d:",a[i][0]);

scanf("%d",&a[i][1]);

printf("B.T of process %d:",a[i][0]);

scanf("%d",&a[i][2]);

printf("Priority of process %d:",a[i][0]);

scanf("%d",&a[i][5]);

}

for(i=0;i<n;i++)

{

                for(j=0;j<n-i-1;j++)

{

                if(a[j][1]>a[j+1][1])

{

swap(&a[j][0],&a[j+1][0]);

swap(&a[j][1],&a[j+1][1]);

swap(&a[j][2],&a[j+1][2]);

swap(&a[j][5],&a[j+1][5]);

}

}

}

a[0][3]=a[0][1];//waiting time

a[0][4]=a[0][2]-a[0][1];//turnaround time

cmpt=a[0][4];//completion time

twt=twt+a[0][3];

ttat=ttat+a[0][4];

for(i=1;i<n;i++)

{

int min=a[i][5];

for(j=i+1;j<n;j++)

{

if(min>a[j][5] && a[j][1]<=cmpt)

{

min=a[j][5];

swap(&a[i][0],&a[j][0]);

swap(&a[i][1],&a[j][1]);

swap(&a[i][2],&a[j][2]);

swap(&a[i][5],&a[j][5]);

}

}

a[i][3]=cmpt-a[i][1];

twt=twt+a[i][3];

cmpt=cmpt+a[i][2];

a[i][4]=cmpt-a[i][1];

ttat=ttat+a[i][4];

}

printf("Process\tA.T\tB.T\tPR\tT.A.T\tW.T\n");

for(i=0;i<n;i++)

{

printf("%d\t%d\t%d\t%d\t%d\t%d\n",a[i][0],a[i][1],a[i][2],a[i][5],a[i][4],a[i][3]);

}

printf("Average turnaround time=%f\n",ttat/n);

printf("Average waiting time=%f\n",twt/n);

return 0;

}
