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

n = int(input("Enter the value of n: "))
for i in range(n):
    for j in range(0 , i+1):
        print("* " , end = "")
    print()
for i in range(n-1,0,-1):
    for j in range(0 , i):
        print("* " , end = "")
    print()

print("______________Program Over_______________")
