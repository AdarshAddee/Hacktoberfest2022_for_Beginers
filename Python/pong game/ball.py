from turtle import Turtle


class Ball(Turtle):
    def __init__(self):
        super().__init__()
        self.shape("circle")
        self.speed('fastest')
        self.color("white")
        self.penup()
        self.x = 10
        self.y = 10
        self.sp = 0.2

    def move(self):
        self.speed("fast")
        x = self.xcor() + self.x
        y = self.ycor() + self.y
        self.goto(x, y)

    def bouncey(self):
        self.y *= -1

    def bouncex(self):
        self.x *= -1
        self.sp *= 0.9

    def reset(self):
        self.goto(0, 0)
        self.sp = 0.2
        self.bouncex()
