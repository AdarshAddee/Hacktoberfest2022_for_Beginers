# Github username: maciek04786
# Aim: The program draws a christmas tree pattern
# Date: 23/10/2022

size = 7

m = (2 * size) - 2

for i in range(0, size):

    for n in range(0, m):
        print(end=" ")

    m = m - 1

    for j in range(0, i + 1):
        print("*", end=" ")
    print(" ")
