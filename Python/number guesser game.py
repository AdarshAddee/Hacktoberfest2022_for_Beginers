import random    #dhruv2003

top_range=input("enter top range: ")

if top_range.isdigit():
  top_range=int(top_range)
  
  if top_range <= 0:
    print("please type no larger than 0")
    quit()
else:
  print("type a number next time !")
  quit()
  
random_number=random.randint(0,top_range) 
guess=0

while True:
  guess += 1
  user_guess=input("Make a guess: ")
  if user_guess.isdigit():
    user_guess = int(user_guess)
  else:
    print("Please type a number!")
    continue
  
  if user_guess == random_number:
    print("YOU GOT IT!")
    break
  elif user_guess > random_number:
    print("You were above the number!")
  else:
    print("you were below the number!!!")
    
print("You got it in",guess,"guesses")        