###################  Problem Statement ##################
"""
Calculate total number of path between 2 coordinates if a person can only move
in rightward and upwards

Example :

coord A = (5,5)
coord B = (10,2)

total path = 15
"""


x1,y1 = map(int, input("Enter the coordinate A with x and y value seperated by space: ").split(" "))
x2,y2 = map(int, input("Enter the coordinate B with x and y value seperated by space: ").split(" "))

if x2<x1 or y2>y1:
    print("Number of path to reach point B from A = 0")
else:
    n = abs(x2-x1)+1
    m = abs(y2-y1)+1
    matrix = [[0 for i in range(n)] for j in range(m)]

    for i in range(1, m):
        for j in range(1, n):
            if i==1 and j==1:
                matrix[i][j]=1
            else:
                matrix[i][j] = matrix[i-1][j]+matrix[i][j-1]

    print("Number of path to reach point B from A = ", matrix[-1][-1])


