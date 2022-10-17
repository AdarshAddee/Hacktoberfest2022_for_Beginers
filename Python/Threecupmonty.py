// Github username: Aishanipach
// Aim: To automate day to day things around us
// Date: 17 October 2022
  
"""THREE CUP MONTY"""
import random

def shuffle_list(my_list):
    random.shuffle(my_list)
    return(my_list)

def checkguess(cup_list, guess):
    if(cup_list[guess]=='0'):
        print("You won!")
        return 1
    else:
        print("You lost :(")
        return -1

def game_play1():
    list1=[' ', '0',' ']
    cup_list1=shuffle_list(list1)
    choice=''
    while choice not in [0, 1, 2] :
    
        choice=int(input("Enter your guess(0,1 or 2): "))
    
    result=checkguess(cup_list1,choice)
    return result


def game_play2():
    list2=[' ',' ','0',' ',' ']
    cup_list2=shuffle_list(list2)
    choice=''
    while choice not in [0, 1, 2, 3, 4] :
    
        choice=int(input("Enter your guess(0,1, 2,3 or 4): "))
    
    checkguess(cup_list2,choice)
    

res=game_play1()
if res==1:
    game_play2()
else:
    print("You should try again")
