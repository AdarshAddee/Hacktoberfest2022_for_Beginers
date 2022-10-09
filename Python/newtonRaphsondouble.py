// Github username: SarinSthapit
// Aim: Newton Raphson Method for Numerical Methods (Double)
// Date: October 9, 2022

from sympy import *
from prettytable import PrettyTable
import math


def iterationmethodDouble(function1, function2, derivativeF_wrt_x, derivativeF_wrt_y, derivativeG_wrt_x, derivativeG_wrt_y, x, y, accuracy):
    
    def f(x, y):
        f = eval(function1)
        return f

    def g(x, y):
        g = eval(function2)
        return g

    def F_x(x, y):
        F_x = eval(derivativeF_wrt_x)
        return F_x
    
    def F_y(x, y):
        F_y = eval(derivativeF_wrt_y)
        return F_y

    def G_x(x, y):
        G_x = eval(derivativeG_wrt_x)
        return G_x

    def G_y(x, y):
        G_y = eval(derivativeG_wrt_y)
        return G_y

    
    i = None
    j = None
    n = 0

    tolerance = 0.5 / (10**(accuracy))
    print(f"The tolerance is {tolerance}.")

    table = PrettyTable(["No.", "x", "y", "f", "g", "a", "b", "c", "d", "D", "D1", "D2", "h", "k"])
    while true:
        f1 = round(f(x, y), accuracy + 1)
        g1 = round(g(x, y), accuracy + 1)
        a = round(F_x(x, y), accuracy + 1)
        b = round(F_y(x, y), accuracy + 1)
        c = round(G_x(x, y), accuracy + 1)
        d = round(G_y(x, y), accuracy + 1)
        capital_D = round((a*d) - (b*c), accuracy + 1)
        D1 = round((g1*b) - (f1*d), accuracy + 1)
        D2 = round((f1*c) - (g1*a), accuracy + 1)
        h = round((D1 / capital_D), accuracy + 1)
        k = round((D2 / capital_D), accuracy + 1)
        n += 1
        
        table.add_row([n, x, y, f1, g1, a, b, c, d, capital_D, D1, D2, h, k])

        if(h == 0 and k == 0):
            break

        x = round(x + h, accuracy + 1)
        y = round(y + k, accuracy + 1)

    print(table)
    print(f"The required root is {x} and {y} after {n} iterations.")
   




functionF = str(input("Enter the first function F(x, y) for x: "))
functionG = str(input("Enter the second function G(x, y) for y: "))
accuracy = int(input("Enter the accuracy of the decimal digits: ")) 
initial_x = float(input("Enter the initial approximation of x: "))
initial_y = float(input("Enter the initial approximation of y: "))

x = symbols('x')
y = symbols('y')

derivativeF_wrt_x = str(diff(functionF, x)) # = ∂F/∂x
derivativeF_wrt_y = str(diff(functionF, y)) # = ∂F/∂y

derivativeG_wrt_x = str(diff(functionG, x)) # = ∂G/∂x
derivativeG_wrt_y = str(diff(functionG, y)) # = ∂G/∂y

iterationmethodDouble(str(functionF), str(functionG), str(derivativeF_wrt_x), str(derivativeF_wrt_y), str(derivativeG_wrt_x), str(derivativeG_wrt_y), initial_x, initial_y, accuracy)
