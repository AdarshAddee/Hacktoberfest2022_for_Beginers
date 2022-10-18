# Github username: raunaksaigal
# Aim: Prints spiral Numbers
# Date: 18 October 2022

n = int(input("n = "))

lst = []
l = []


for i in range(n):
    l = []
    for j in range(n):  # creating an n by n matrix whose elments are 0
        l.append(0)
    lst.append(l)


p = 0

'''
p = 0 right
p = 1 down
p = 2 left
p = 3 up

'''
num = 1

top = 0                 # setting the initial 'pointers' for the start and end
left = 0
bottom = n
right = n


while num != n**2+1:
    if p == 0:
        for i in range(left,right):         # prints from left to right
            
            lst[top][i]=num
            num+=1
            
        top+=1
        p = 1
        

    elif p == 1:
        for i in range(top, bottom):        # prints from top to bottom
            
            lst[i][right-1]=num
            num+=1
        right-=1
        p = 2
        

    elif p == 2:
        for i in range(right, left, -1):    # prints right to left the -1 reverses the index numbers
            
            lst[bottom-1][i-1]=num
            num+=1
        bottom-=1
        p = 3
        p

    elif p == 3:
        for i in range(bottom, top, -1):    # prints from bottom to top
            
            lst[i-1][left]=num
            num+=1
        left+=1
        p = 0
        

for i in lst:
    for j in i:
        print(j,end='\t')   
    print('\n')