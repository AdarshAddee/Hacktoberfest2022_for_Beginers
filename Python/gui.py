#   Name: Kaushal ratnapagol
from tkinter import *
from tkinter import messagebox

Player1 = 'X'
stop_game = False

def clicked(r,c):
	
	
	global Player1
	

	if Player1 == "X" and states[r] == 0 and stop_game == False:
		b[r].configure(text = "X")
		states[r] = 'X'
		Player1='O'

	
	if Player1 == 'O' and states[r] == 0 and stop_game == False:
		b[r].configure(text = 'O')
		states[r] = "O"
		Player1 = "X"


	for i in range(3):
		if states[i][0] == states[i][1] == states[i][2] !=0:
			stop_game = True

			winner = messagebox.showinfo("Winner", states[i][0] + " Won")
		
			break

		elif states [0][i] == states[1][i] == states[2][i] != 0:
			stop_game = True

			winner = messagebox.showinfo("Winner", states[0][i]+ " Won!")
			break

		elif states[0][0] == states[1][1] == states[2][2] !=0:
			stop_game = True

			winner = messagebox.showinfo("Winner", states[0][0]+ " Won!")
			break

		elif states[0][2] == states[1][1] == states[2][0] !=0:
			stop_game = True

			winner = messagebox.showinfo("Winner" , states[0][2]+ " Won!")
			break

		elif states[0][0] and states[0][1] and states[0][2] and states[1][0] and states[1][1] and states[1][2] and states[2][0] and states[2][1] and states[2][2] != 0:
			stop_game = True

			winner = messagebox.showinfo("tie", "Tie")

# Design window
#Creating the Canvas
root = Tk()
# Title of the window			
root.title("GeeksForGeeks-:Tic Tac Toe")
root.resizable(0,0)

#Button
b = [
	[0,0,0],
	[0,0,0],
	[0,0,0]]

#text for buttons
states = [
	[0,0,0],
	[0,0,0],
	[0,0,0]]

for i in range(3):
	for j in range(3):
										
		b[i][j] = Button(
						height = 4, width = 8,
						font = ("Helvetica","20"),
						command = lambda r = i, c = j : clicked(r,c))
		b[i][j].grid(row = i, column = j)


mainloop()		
