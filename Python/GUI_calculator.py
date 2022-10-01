## github username:- AdityaWadkar
# This project is of gui calculator which is created using tkinter in only 50 lines.
"""
Step to run:
prerequisite : python of version 3 or above should be installed in your system
1. copy-Paste or download this file in code editor.
2. run the file to see calculator .
"""

from tkinter import *
import tkinter.messagebox as t
a,y,yz,aw=0,70,"red","pink"
def click(event):
    global s
    text = event.widget.cget("text")
    if text == "=":
        a=s.get()
        if "^" in s.get():
            a=a.replace("^","**")
        if "x" in s.get():
            a=a.replace("x","**")
        try:
            value=eval(a)
            s.set(value)
            screen.update()
        except Exception as e:
            t.showerror("Error!!","Please select 2 numbers")
            print(e)
    elif text =="C":
        s.set("")
        screen.update()
    else:
        s.set(s.get()+text)
        screen.update()
root=Tk()
root.geometry("335x420")
root.title("Calculator")
root.config(bg="#FFDEAD")
root.wm_iconbitmap("calculate.ico")
s=StringVar()
s.set("")
screen =Entry(root,textvar=s, font="verdena 20 bold",justify=RIGHT)
screen.pack(pady=10)
text = ("7", "8", "9", "C", "4", "5", "6", "+", "1", "2", "3", "-", "^", "0", ".", "x")
def button (text,l,m):
    if text =="-" or text == "." or text=="/":
        f=9
    else:
        f=6
    b = Button(root,text=text, font="lucida 20 bold", padx=f, pady=0,activeforeground=yz,bg=aw)
    b.place(x=l,y=m)
    b.bind("<Button-1>", click)
for m in range(4):
    x=27
    for l in range (4):
        button(text[a],x,y)
        a=a+1
        x=x+80
    y=y+70
b = Button(root,text="/", font="lucida 20 bold", width=3, height=1,activeforeground=yz,bg=aw)
b.place(x=267,y=350)
b.bind("<Button-1>", click)
b = Button(root,text="=", font="lucida 20 bold", width=13, height=1,activeforeground=yz,bg=aw)
b.place(x=23,y=350)
b.bind("<Button-1>", click)
root.mainloop()
