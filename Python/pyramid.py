# github Username - seerat16
# aim : to print a pyramid of length n 
# date: 4th October 2022

depth = int(input("Enter length of pyramid: "))

n = 0

for i in range(1, depth+1):
    for space in range(1, (depth-i)+1):
        print(end="  ")
   
    while n!=(2*i-1):
        print("* ", end="")
        n += 1
   
    n = 0
    print()