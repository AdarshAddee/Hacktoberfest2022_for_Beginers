# Github username: piyushg1
# Aim: A program with class and objects that prints fibonacci series of first n numbers
# Date: 09-10-2022

class Fib:
    def print_fib(self, n: int):
        if n < 0:
            return
        elif n == 1:
            print(1)
            return

        a, b = 1, 1
        print(a, end=', ')
        print(b, end=', ')
        # if n >= 3:
        while n > 2:
            c = a+b
            print(c, end=', ')
            a = b
            b = c  # swapping
            n -= 1


obj = Fib()
obj.print_fib(10)
