# Added By Wahaj Raza
# Mine sweeper Game using python

from tkinter import *
import settings
import utils
from cell import Cell

root = Tk()
#SETTINGS OF WINDOW
root.configure(bg="black")
root.geometry(f"{settings.WIDTH}x{settings.HEIGHT}")
root.title("Mine Sweeper Game")
root.resizable(False,False)

top_frame = Frame(
    root,
    bg="black",
    width=settings.WIDTH,
    height=utils.height_perct(25),
)
top_frame.place(x=0,y=0)

game_title = Label(
    top_frame,
    bg="black",
    fg="white",
    text="M I N E  S W E E P E R  G A M E",
    font=("LCDMono2",48)
)
game_title.place(x=utils.width_perct(10),y=utils.height_perct(5))

left_frame = Frame(
    root,
    bg="black",
    width=utils.width_perct(25),
    height=utils.height_perct(75),
)
left_frame.place(x=0,y=utils.height_perct(25))

center_frame = Frame(
    root,
    bg="black",
    width=utils.width_perct(75),
    height=utils.height_perct(75)
)
center_frame.place(x=utils.width_perct(25),y=utils.height_perct(25))

for x in range(settings.GRID_SIZE):
    for y in range(settings.GRID_SIZE):
        c = Cell(x,y)
        c.create_btn_object(center_frame)
        c.cell_btn_object.grid(column=x,row=y)

#CALL THE LABEL FROM THE CELL CLASS
Cell.create_cell_count_label(left_frame)
Cell.cell_count_label_object.place(x=0,y=0)
Cell.randomize_mines()
#RUN THE WINDOW
root.mainloop()