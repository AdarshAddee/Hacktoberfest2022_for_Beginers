# Program to print diamond shape
# github.com/djharshit

n = eval(input("Enter a number of n: "))
for i in range(n):
    print(" "*(n-i), "*"*(i*2+1))
    
for i in range(n-2, -1, -1):
    print(" "*(n-i),"*"*(i*2+1))
    
