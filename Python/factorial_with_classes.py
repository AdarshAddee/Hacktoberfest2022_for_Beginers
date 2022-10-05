# GitHub Username: https://github.com/Aditya-Kumar-Sahu/
# Aim: to calculate factorial with classes
# Date: 05/10/22

class number:
    def __init__(self):
        self.number=None
        self.fact=1

    def factorial(self):
        n=self.number
        while True:
            if n==1:
                break
            else:
                self.fact*=n
                n=n-1
        return self.fact

    def input(self):
        try:
            self.number=int(input("Enter an integer: "))
        except:
            print("Invalid input!!\n")
            print("Enter again-")
            self.input()

if __name__ == '__main__':
    num=number()
    num.input()
    fact=num.factorial()
    print("Factorial of given number is:", fact)
    