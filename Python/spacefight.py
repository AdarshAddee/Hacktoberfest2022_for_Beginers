import pygame as pg
from pygame import mixer
import cv2
import os
import random
import math

# Intialize the pygame
pg.init()
mixer.init()
# All the icon image and music links are present here
space = r'.Pygame\space-invaders.png'
ship = pg.image.load(space)
ico = r'.Pygame\arcade-game.png'
icon = pg.image.load(ico)
enem = r'.Pygame\spaceship.png'
enemy = pg.image.load(enem)
bgt = r'.Pygame\background.png'
background = pg.image.load(bgt)
bul = r'.Pygame\bullet.png'
bullet = pg.image.load(bul)
mad = r'.Pygame\bc.wav'
las = r'.Pygame\laser.wav'
exp = r'.Pygame\explosion.wav'

# Screen size
screen = pg.display.set_mode((800,600))

# main music
def back():
    mixer.music.load(mad)
    mixer.music.play(-1)

# caption
pg.display.set_caption("fuck off")

# Score
score = 0
font = pg.font.Font('freesansbold.ttf',32)

def show(score):
    scorevalue = font.render("Score : "+ str(score), True, (255,255,120))
    screen.blit(scorevalue, (10,10))

# ICON
# link = r'C:\Users\suyash\Desktop\sticker.png'
# img = cv2.imread(link)
# img = cv2.resize(img,(32,32),interpolation = cv2.INTER_CUBIC)
# image = cv2.imwrite('pygame random.png',img)
# loc = r'C:\Users\suyash\Desktop\KACHRA\laohub\pygame random.png'
# icon = pg.image.load(loc)
pg.display.set_icon(icon)

# Postion player function 
playx = 350
playy = 500
changex = 0
def spaceship(x,y):
        screen.blit(ship,(x, y))

# Postion enemy function 
enemyx = []
enemyy = []
changeenemyx = []
for i in range(score + 1):
    enemyx.append(random.randint(10,750))
    enemyy.append(random.randint(50,200))
    changeenemyx.append(1)
changeenemyy = 10
def enemyship(x,y):
        screen.blit(enemy,(x, y))

# Postion bullet function 
bulletx = 0
bullety = 500
bulletstate = "r"
bulletchange = 7
def bulletmove(x,y):
    global bulletstate
    global bullety
    
    bulletstate = "f"
    screen.blit(bullet,(x+8, y+3))
    if bullety <= 0:
        bulletstate = "r"
        bullety = 500

# Collision
def collision(x1,x2,y1,y2):
    x = x1 - x2 - 16
    y = y1 - y2 - 16
    dist = math.sqrt(x*x + y*y)
    if dist<= 30 :
        return True
    else:
        return False

def other(x):
    mixer.music.load(x)
    mixer.music.play()

back()

clock = pg.time.Clock()
# The game loop command it is what stops the program to close( all the permenant things)
run = True
while run:
    clock.tick(40)
    for event in pg.event.get():
        if event.type == pg.QUIT:
            run  = False
    
    # Movement of the space ship
    if event.type == pg.KEYDOWN:
        if event.key == pg.K_RIGHT:
            changex = 2
        elif event.key == pg.K_LEFT:         
            changex = -2
            
        elif event.key == pg.K_UP:
            if bulletstate == "r":
                bulletstate = "f"
                bulletx = playx
                other(las)
                #back()

    # Movement stop
    if event.type == pg.KEYUP:
        if event.key == pg.K_RIGHT:
            changex = 0
        if  event.key == pg.K_LEFT:
            changex = 0
        
    # This is to give the screen a color
    screen.fill((0, 0, 20))                          # RGB

    # Background
    screen.blit(background,(0,0))
    
    # Movement
    playx = playx + changex 

    # Movement restrictions
    # PLAYER
    if playx <= 10:
        playx = 10
    if playx >= 750:
        playx = 750 

    # Enemy 
    # ENEMY
    for i in range(score + 1):
        
        col = collision(bulletx,bullety,enemyx[i],enemyy[i])
        if col == True:
            other(exp)
            #back()
            bullety = 500
            bulletstate = "r"
            score = score + 1
            
            enemyx.append(random.randint(10,750))
            enemyy.append(random.randint(50,200))
            changeenemyx.append(1)

            enemyx[i] = random.randint(10,750)
            enemyy[i] = random.randint(50,200)
            pg.display.update() 

        enemyx[i] = enemyx[i] + changeenemyx[i]
        if enemyx[i] <= 10:
            changeenemyx[i] = 1
            enemyy[i] = enemyy[i] + changeenemyy
        if enemyx[i] >= 750:
            changeenemyx[i] = -1 
            enemyy[i] = enemyy[i] + changeenemyy


        enemyship(enemyx[i],enemyy[i]) 
    
        
    if bulletstate == "f":
        bulletmove(bulletx,bullety)
        bullety = bullety - bulletchange 
        
    show(score)
    spaceship(playx, playy)
    
    pg.display.update()                              # To update your screen


##os.remove(loc)
