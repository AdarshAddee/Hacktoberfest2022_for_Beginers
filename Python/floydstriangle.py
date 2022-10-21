#Basically, Floyd’s triangle is an arrangement of natural numbers from left to right in a right triangle.
#The first line contains a 1, the second line contains 2 and 3. The next line contains 4, 5 and 6.
#The numbers continue infinitely in this pattern.

n = int(input("Enter number of rows of floyd`s trangle: "))
k = 1
for i in range(1, n + 1):
    for j in range(1, i + 1):
        print(k, end=" ")
        k = k + 1
    print()
