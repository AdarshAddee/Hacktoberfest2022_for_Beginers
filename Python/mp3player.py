# Hey Guys, I'm Ratnesh 
# This code will help you to play mp3 music

from operator import imod 
import pygame #used to create video gaem
import tkinter as tkr #used to develop GUI
from tkinter import *
from tkinter.filedialog import askdirectory #it permit to select dir
import os #permits to interact with the operating system

music_plr = tkr.Tk()
music_plr.title("Sit back and Chill")
music_plr.geometry("450x350")

directory = askdirectory()
os.chdir(directory) #it permits to change the current dir
song_lis = os.listdir() #it returns the list of files song

play_list = tkr.Listbox(music_plr, font="Helvetica 12 bold", bg="yellow", selectmode= tkr.SINGLE)

for item in song_lis:
    pos = 0
    play_list.insert(pos, item)
    pos +=1 

pygame.init()
pygame.mixer.init()

def play():
    pygame.mixer.music.load(play_list.get(tkr.ACTIVE))
    var.set(play_list.get(tkr.ACTIVE))
    pygame.mixer.music.play()

def stop():
    pygame.mixer.music.stop()

def pause():
    pygame.mixer.music.pause()

def unpause():
    pygame.mixer.music.unpause()

Button1 = tkr.Button(music_plr, width=5, height=3, font="Helvetica 12 bold", text="PLAY", command=play,bg="blue",fg="white")
Button2 = tkr.Button(music_plr, width=5, height=3, font="Helvetica 12 bold", text="STOP", command=stop,bg="red",fg="white")
Button3 = tkr.Button(music_plr, width=5, height=3, font="Helvetica 12 bold", text="PAUSE", command=pause,bg="purple",fg="white")
Button4 = tkr.Button(music_plr, width=5, height=3, font="Helvetica 12 bold", text="UNPAUSE", command=unpause,bg="orange",fg="white")

var = tkr.StringVar()
song_title = tkr.Label(music_plr, font="Helvetica 12 bold", textvariable=var)

song_title.pack()
Button1.pack(fill="x")
Button2.pack(fill="x")
Button3.pack(fill="x")
Button4.pack(fill="x")
play_list.pack(fill="both",expand="yes")
music_plr.mainloop()