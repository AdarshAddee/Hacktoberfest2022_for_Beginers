import pygame
import random
pygame.init()
screen = pygame.display.set_mode([1000, 600])

pygame.font.init()
myfont = pygame.font.SysFont("Comic Sans MS", 50)
rockColour = (0, 0, 0)
rockLight = (100, 100, 100)
paperColour = (255, 255, 255)
paperColourBorder = (0, 0, 0)
paperBorderLight = (100, 100, 100)
scissorColour = (0, 0, 0)
scissorLight = (100, 100, 100)
choice=["rock","paper","scissors"]
P1Choice = ""
P2Choice = ""
Player1 = True  # user playing the game
Player2 = False  # computer player the game by randomly selecting a choice
white = (250, 250, 250)
black = (0, 0, 0)
enter= False
# Run until the user asks to quit
running = True

def RockPaperScissor(choice):
    if  choice == "rock":
        pygame.draw.circle(screen, rockColour, (200, 300), (75))
        textsurface = myfont.render("ROCK", False, black)
        screen.blit(textsurface, (137, 150))
    else:
        pygame.draw.circle(screen, rockLight, (200, 300), (75))

    if choice == "paper":
        pygame.draw.rect(screen, paperColourBorder, (400, 225, 150, 150))
        pygame.draw.rect(screen, paperColour, (410, 235, 130, 130))
        textsurface = myfont.render("PAPER", False, black)
        screen.blit(textsurface, (400, 150))
    else:
        pygame.draw.rect(screen, paperBorderLight, (400, 225, 150, 150))
        pygame.draw.rect(screen, paperColour, (410, 235, 130, 130))

    if choice == "scissors":
        pygame.draw.line(screen, scissorColour, (700, 375), (850, 225), 20)
        pygame.draw.line(screen, scissorColour, (850, 375), (700, 225), 20)
        textsurface = myfont.render("SCISSORS", False, black)
        screen.blit(textsurface, (635, 150))

    else:
        pygame.draw.line(screen, scissorLight, (700, 375), (850, 225), 20)
        pygame.draw.line(screen, scissorLight, (850, 375), (700, 225), 20)
        
def winner():
     result=""
     resultText=""
     if P1Choice == P2Choice:
        result = "draw"
     if((P1Choice=="rock" and P2Choice =="paper" ) or (P1Choice =="paper" and P2Choice =="rock")):
        result = "paper"
     elif((P1Choice=="rock" and P2Choice=="scissors") or (P1Choice=="scissors" and P2Choice=="rock")):
        result = "rock"
     elif((P1Choice=="paper" and P2Choice=="scissors") or (P2Choice=="scissors" and P1Choice=="paper")):
        result = "scissors"
     print("P1Choice {} P2Choice {} result {}",P1Choice,P2Choice,result)
     if result == "draw":
        resultText = "Its a tie"
     if result == P1Choice:
        resultText = "Player 1 wins"
     elif result == P2Choice:
        resultText = "Player 2 wins"
     else:
        resultText = "Its a tie"
     return resultText

def text(text,x,y):
    pygame.draw.rect(screen, (255,255,255), (x, y, 180, 130))
    # pygame.draw.rect(screen, (255,255,255), (x+20, y+10, 160, 110))
    textsurface = myfont.render(text, False, black)
    screen.blit(textsurface, (x, y))

while running:
    mouseclick = False  # reset all these
    mouserock = False
    mousepaper = False
    mousescissors = False
    click = [False, False]  # Mouse button clicks

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.MOUSEBUTTONDOWN and Player1 == True and Player2 == False:
            mouseclick = True
            mousepos = pygame.mouse.get_pos()
            print(mousepos)
            print(event)
            if event.button== 1:
                click[event.button - 1] = True  # which button was pressed
            mouserock = 125 + 150 > mousepos[0] > 125 and 225 + 150 > mousepos[1] > 225
            mousepaper = 400 + 150 > mousepos[0] > 400 and 225 + 150 > mousepos[1] > 225
            mousescissors = 850 > mousepos[0] > 700 and 375 > mousepos[1] > 255
            mouseenter=400 +180 > mousepos[0]>400 and 390 + 130 > mousepos[1] > 390
            if (mousepaper and click[0] == True):
                P1Choice = "paper"
                P2Choice = choice[random.randint(0, 2)]
                enter=False
            if (mousescissors and click[0] == True):
                P1Choice = "scissors"
                P2Choice = choice[random.randint(0, 2)]
                enter=False
            if (mouserock and click[0] == True):
                P1Choice = "rock"
                P2Choice = choice[random.randint(0, 2)]
                enter=False
            if (mouseenter and click[0] == True):
                enter = True
        elif event.type == pygame.MOUSEBUTTONDOWN and Player1 == False and Player2 == True:
            mouseclick = True
            mousepos = pygame.mouse.get_pos()
            if event.button== 1:
                    click[event.button - 1] = True  # which button was pressed
            mounseplayagain=400 +180 > mousepos[0]>400 and 470 + 130 > mousepos[1] > 470
            if (mounseplayagain and click[0] == True):
                print("play again")
                P1Choice = ""
                P2Choice = ""
                enter = False
                Player1 = True
                Player2 = False

    screen.fill(white)
    if Player1 == True and Player2 == False:
        textsurface = myfont.render("Player 1", False, black)
        screen.blit(textsurface, (400, 25))
        text("Enter",400,390)
        RockPaperScissor(P1Choice)
        if enter and P1Choice != "":
            Player1 = False
            Player2 = True
    if Player1 == False and Player2 == True:
            textsurface = myfont.render("Player 1", False, (255, 255, 255))
            screen.blit(textsurface, (400, 25))
            textsurface = myfont.render("Player 2", False, (0, 0, 0))
            screen.blit(textsurface, (400, 25))
            RockPaperScissor(P2Choice)
            resultText=winner()
            text(resultText,370,390)
            text("Play Again",400,470)
    pygame.display.flip()
pygame.quit()
