# Github username: SS56Bo
# Aim: A simple product to print pattern using function
# Date: 22/10/2022


def right_tri(n):
    for i in range(0,n):
        for j in range(0, i+1):
            print ("* ", end="")
        print ("\r")

def left_tri(n):
    k=2*n-2
    for i in range (0,n):
        for j in range (0,k):
            print (end="")
        k=k-2
        for j in range [:i+1]:
             print ("* ", end="")
        print ("\r")

def triangle(n):   
    k = n - 1
 
    
    for i in range(0, n):
     
        
        for j in range(0, k):
            print(end=" ")
     
       
        k = k - 1
     
        for j in range(0, i+1):
         
           
            print("* ", end="")
     
       
        print("\r")
 
print ("Press 1: Right-Angled Triangle")
print ("Press 2: Left-Angled Triangle")
print ("Press 3: Triangle")
j=int (input("Enter your choice: "))
if (j==1):
    num=int(input("Enter length of pattern: "))
    right_tri(num)
elif (j==2):
    num=int(input("Enter length of pattern: ")) 
    left_tri(num)
elif (j==3):
    num=int(input("Enter length of pattern: "))
    triangle(num)