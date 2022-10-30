'''  
   Github username: @GAUTHAMI-S
   Aim: Program to print a pattern using turtle library
   Date: 30/10/2022
'''

import turtle
colors=['red','yellow','green','purple','blue','orange']

t= turtle.Pen()
t.speed(10)
turtle.bgcolor("black")

for x in range(200):
    t.pencolor(colors[x%6])
    t.width(x/100+1)
    t.forward(x)
    t.left(59)

turtle.done()
