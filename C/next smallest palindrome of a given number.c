#include <stdio.h>
#include <stdlib.h>

int nextPalindromeGenerate(int n)
    {   
       int ans=1, digit, rev_num=0, num;              
    if(n<10)
        {   
            ans=0;
			return n+1;
        }
        num=n;
        while(ans!=0)
        {   rev_num=0;digit=0;
            n=++num;

            while(n>0)       
            {
                digit=n%10;
                rev_num=rev_num*10+digit;
                n=n/10;
            }
            if(rev_num==num)   
            {
                ans=0;
				return num;
            }
            else ans=1;
        }
		return num;
    }
  int main(void)
    {          
       int n = 121;
       if (n>0);
		{	
		 printf("Next smallest palindrome of %d is %d", n, nextPalindromeGenerate(n));
		}         
		return 0;
   }
