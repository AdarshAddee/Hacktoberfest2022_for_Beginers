# Created by - theutpal01

def printNums(u, v):
    for i in range(u, v + 1):
        print(i, end=", ")
    print(end=".")
  
  
def main():
    u = int(input("Enter the starting number: "))
    v = int(input("Enter the ending number: "))
    printNums(u, v)

main()
