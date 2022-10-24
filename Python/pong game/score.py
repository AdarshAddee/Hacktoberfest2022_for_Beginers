from turtle import Turtle


class Score(Turtle):

    def __init__(self):
        super().__init__()
        self.color("white")
        self.penup()
        self.hideturtle()
        self.s = 0
        self.s1 = 0
        self.up()

    def up(self):
        self.clear()
        self.goto(-100, 200)
        self.write(self.s, align="center", font=("Courier", 50, "normal"))
        self.goto(100, 200)
        self.write(self.s1, align="center", font=("Courier", 50, "normal"))

    def le(self):
        self.s += 1
        self.up()

    def ri(self):
        self.s1 += 1
        self.up()
