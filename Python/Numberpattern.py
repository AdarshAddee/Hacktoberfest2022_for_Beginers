num = 1
n = int(input("Enter the number of rows you want:"))
for i in range(n):
    for j in range(i+1):
        print(num,end="")
        num = num + 1
    num = 1
    print()
