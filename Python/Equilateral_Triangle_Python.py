#GitHub UserName:- notsointresting

size = int(input("ENTER SIZE---> "))
m = (2 * size) - 2
for i in range(0, size):
    for _ in range(0, m):
        print(end=" ")
    m = m - 1
    for _ in range(0, i + 1):
        print("* ", end=' ')
    print(" ")
