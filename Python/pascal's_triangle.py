# Pascal's Triangle

rows = int(input("Enter the number of rows: "))
flag = 1

for i in range(1, rows+1):
    for space in range(1, rows-i+1):
        print(" ",end="")
    for j in range(0, i):
        if j==0 or i==0:
            flag = 1
        else:
            flag = flag * (i - j)//j
        print(flag, end = " ")
    print()