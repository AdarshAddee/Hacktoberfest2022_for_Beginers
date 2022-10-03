/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sn=new Scanner(System.in);
		int t=sn.nextInt();
		for(int i=0;i<t;i++)
		{
		    int a=sn.nextInt();
		    int b=sn.nextInt();
		    int c=sn.nextInt();
		    int d=sn.nextInt();
		    if(a-c<b-d)
		        System.out.println("First");
		    else if(a-c>b-d)
		        System.out.println("Second");
		    else
		        System.out.println("Any");
		}
	}
}
