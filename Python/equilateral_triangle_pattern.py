# Github Username - iamrahul8 (https://github.com/iamrahul8)
# Equilateral triangle pattern in python
# Date of coding : 5-10-22

print("Print equilateral triangle Pyramid using stars")

size = 7 #input the size of triangle

m = (2 * size) - 2

for i in range(0, size):

    for j in range(0, m):

        print(end=" ")

    m = m - 1 # decrementing m after each loop

    for j in range(0, i + 1):

        # printing full Triangle pyramid using stars

        print("*", end=' ')

    print(" ")
