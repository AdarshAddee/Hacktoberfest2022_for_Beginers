from tkinter import Button,Label
import random
import settings
import ctypes
import sys

class Cell:
    all=[]
    cell_count_label_object=None
    cell_count=settings.CELL_COUNT
    def __init__(self,x,y, is_mine=False):
        self.is_mine=is_mine
        self.cell_btn_object = None
        self.x=x
        self.y=y
        self.is_mine_candidate=False
        self.is_open=False
        #Append the object to cell.all list
        Cell.all.append(self)
    def create_btn_object(self,location):
        btn=Button(location,width=12,height=4)
        btn.bind("<Button-1>",self.left_click_actions) #LEFT CLICK
        btn.bind("<Button-3>",self.right_click_actions) #RIGHT CLICK
        self.cell_btn_object = btn

    @staticmethod
    def create_cell_count_label(location):
        lbl = Label(location,text=f"CELLS LEFT : {Cell.cell_count}",
                    bg="black",
                    fg="white",
                    font=("LCDMono2",20),
                    width=20,
                    height=4)
        Cell.cell_count_label_object =  lbl
    def left_click_actions(self,event):
        if self.is_mine:
            self.show_mine()
        else:
            if self.sorrounded_cells_mine_length == 0:
                for cell_object in self.sorrounded_cells:
                    cell_object.show_cell()
            self.show_cell()
            #PLAYER WIN
            if Cell.cell_count == settings.MINES_COUNT:
                ctypes.windll.user32.MessageBoxW(0, "Congratulations!! You won the Game", "Game Over", 0)
                sys.exit()

        self.cell_btn_object.unbind("<Button-1>")
        self.cell_btn_object.unbind("<Button-3>")
    def get_cell_by_axis(self,x,y):
        #return the cell obect based on the values of X AND Y
        for cell in Cell.all:
            if cell.x==x and cell.y==y:
                return cell
    @property
    def sorrounded_cells(self):
        cells = [
            self.get_cell_by_axis(self.x - 1, self.y - 1),
            self.get_cell_by_axis(self.x - 1, self.y),
            self.get_cell_by_axis(self.x - 1, self.y + 1),
            self.get_cell_by_axis(self.x, self.y - 1),
            self.get_cell_by_axis(self.x + 1, self.y - 1),
            self.get_cell_by_axis(self.x + 1, self.y),
            self.get_cell_by_axis(self.x + 1, self.y + 1),
            self.get_cell_by_axis(self.x, self.y + 1)
        ]
        cells = [cell for cell in cells if cell is not None]
        return cells

    @property
    def sorrounded_cells_mine_length(self):
        counter=0
        for cell in self.sorrounded_cells:
            if cell.is_mine:
                counter+=1
        return counter
    def show_cell(self):
        if not self.is_open:
            Cell.cell_count-=1
            self.cell_btn_object.configure(text=f"{self.sorrounded_cells_mine_length}")
            #REPLACE THE TEXT OF CELL COUNT WITH NEW COUNT
            if Cell.cell_count_label_object:
                Cell.cell_count_label_object.configure(text=f"CELLS LEFT : {Cell.cell_count}")
            self.cell_btn_object.configure(bg="SystemButtonFace")
        #Mark the cell as opened
        self.is_open=True
    def show_mine(self):
        #LOGIC TO INTERUPT THE GAME AND SHOW A MESSAGE THAT ITS A MINE
        self.cell_btn_object.configure(bg="red")
        ctypes.windll.user32.MessageBoxW(0,"You Clicked on a Mine","Game Over",0)
        sys.exit()

    def right_click_actions(self,event):
        if not self.is_mine_candidate:
            self.cell_btn_object.configure(bg="orange")
            self.is_mine_candidate=True
        else:
            self.cell_btn_object.configure(bg="SystemButtonFace")
            self.is_mine_candidate=False



    @staticmethod
    def randomize_mines():
        picked_cells=random.sample(Cell.all,settings.MINES_COUNT)
        for picked_cell in picked_cells:
            picked_cell.is_mine = True

    def __repr__(self):
        return f"Cell{self.x},{self.y}"