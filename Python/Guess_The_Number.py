# Program by : Swayamshree Mohanty
# GitHub : https://github.com/Swayms-stack

''' Algorithm 
1. Import the random module.
2. Ask the user's name.
3. Greet the user and specify the number range.
4. Use the randint() method (from the random module) which returns an integer number selected element from the specified range.
4. Intialize the start and end range of the number.
5. Use for loop to specify the number of guesses allowed.
6. Guess the number as middle of the search space.
7. If the number guessed is correct, then print Good Job and terminate the program.
8. If the guess is wrong, inform the user that guessed number is less or higher than the guessed number. 
9. If the user used all the guesses and couldn't answer correctly, reveal the correct answer and inform the number of guesses taken.'''

# Import the random module
import random

# Accept the User Name
user = input('What is your name ? ')
# Greet the user
print ('Hello ' + user + ' I am thinking of a number between 1 & 30')
secret_number = random.randint (1, 30)

# Take user's guess
for Guess in range (1,6) :
    print ('Take a guess ')
    guess = int(input ())
    
# If - else condition (only for wrong guesses)
    if  guess > secret_number :
        print ('Too High')
    elif  guess < secret_number :
        print ('Too Low')
    else :
        break
# In case of a correct guess (print the number of guesses taken)
if guess == secret_number :
    print ('Good Job ! You took ' + str(Guess) + ' guesses')
# In case the user couldn't guess correctly and used all guesses, reveal the answer
else :
    print ('No more guesses left ' + str(secret_number))
