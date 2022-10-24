from turtle import Turtle, Screen
from paddle import Paddle
from ball import Ball
from score import Score
import time

s = Screen()

s.bgcolor("black")
s.setup(width=800, height=600)
s.tracer(0)
s.title("PONG GAME")

t = Paddle((350, 0))
t.speed("fast")
t1 = Paddle((-350, 0))
t1.speed("fast")
b = Ball()
sc = Score()

s.listen()

s.onkey(t.up, "Up")
s.onkey(t.down, "Down")
s.onkey(t1.up, "w")
s.onkey(t1.down, "s")

on = True

while on:
    time.sleep(b.sp)
    s.update()
    b.move()

    if b.ycor() > 280 or b.ycor() < -280:
        b.bouncey()

    if b.distance(t) < 50 and b.xcor() > 320 or b.distance(t1) < 50 and b.xcor() < -320:
        b.bouncex()

    if b.xcor() > 360:
        b.reset()
        sc.le()

    if b.xcor() < -360:
        b.reset()
        sc.ri()

s.exitonclick()
