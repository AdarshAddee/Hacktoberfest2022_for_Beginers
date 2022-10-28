#factorial program
n=int(input('Enter a number : '))
fact=1
if n>0:
    for i in range(1,n+1):
        fact=fact*i
    print('Factorial value : ' + str(fact))
    
elif n<0:
    print('Invalid number..Enter a positive number!!')
    
else:
    print('Factorial value : ' + str(fact))
