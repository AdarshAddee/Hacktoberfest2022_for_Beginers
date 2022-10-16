# Github username: neutralWire
# Aim: To contribute to open source community
# Date: 16/10/2022

# This program returns the pattern according the input of the user, otherwise 9if invalid input is entered the it will return -1
def solution(n):
    if n<1:
        return -1;
    string= ""
    if(n>0):
        for row in range(n):
            for column in range(row+1):
                string+="*"
            if row==n-1:
                break
            string+="\n"
    return string

n=int(input("Enter the height of the pattern: "))
print(solution(n))