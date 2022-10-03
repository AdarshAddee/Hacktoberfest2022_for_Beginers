# Github username = wackysoul

class factorial(object):
    def __init__(self, number):
        self.number = number
    def factorial(self):
        if self.number == 1:
            return 1
        else:
            result = self.number * factorial(self.number-1).factorial()
            return result

def main():
    num = int(input("Enter number to calculate factorial: "))
    fact = factorial(num)
    print(fact.factorial())

if __name__ == "__main__":
    main()