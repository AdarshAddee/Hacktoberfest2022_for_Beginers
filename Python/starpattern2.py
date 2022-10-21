"""
star pattern : It takes input from the user and produces the star pattern accordingly as given below..

for eg :-- 
Inout: 

Enter the value of n: 5
Output:
*
* *
* * *
* * * *
* * * * *
* * * *
* * *
* *
*

Enter the value of n: 8
Output:
*
* *
* * *
* * * *
* * * * *
* * * * * *
* * * * * * *
* * * * * * * *
* * * * * * *
* * * * * *
* * * * *
* * * *
* * *
* *
*





"""

n = int(input("Enter value of n in middle: "))
for row in range(0,n*2):
    if row > n :
        print('* '*(n*2-row))
    else :
        print('* '*row)
        
