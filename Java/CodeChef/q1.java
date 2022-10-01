// solution to problem : https://www.codechef.com/submit/NEWPIECE


import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
public static void main (String[] args) throws java.lang.Exception
{
// your code goes here
Scanner sc = new Scanner(System.in);
int t=sc.nextInt();
while(t-->0){
    int x = sc.nextInt();
    int y = sc.nextInt();
    int p = sc.nextInt();
    int q = sc.nextInt();
    if(x==p && y==q)
        System.out.println(0);
    else if((x+y)%2==(p+q)%2)
        System.out.println(2);
    else System.out.println(1);
}
}
}

