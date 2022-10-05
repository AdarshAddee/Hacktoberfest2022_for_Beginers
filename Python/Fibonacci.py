n = int(input('Enter a number: '))
def Fib(n):
   
    if n < 0:
        print("Incorrect input")
        
    elif n == 0:
        return 0
 
    elif n == 1 or n == 2:
        return 1
 
    else:
        return Fib(n-1) + Fib(n-2)
print(Fib(n))
