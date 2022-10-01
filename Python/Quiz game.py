print("Welcome to my computer Quiz!")
decision = input("Do you want to play? ")
score = 0
if decision.upper() == "YES" or decision.upper() == "S":
    answer = input("What does CPU stand for? ")
    if answer.upper() == "CENTRAL PROCESSING UNIT":
        print("Correct!")
        score += 1
    else:
        print("Incorrect!")
    answer2 = input("What does GPU stand for? ")
    if answer2.upper() == "GRAPHICS PROCESSING UNIT":
        print("Correct!")
        score += 1
    else:
        print("Incorrect!")
    answer3 = input("What does RAM stand for? ")
    if answer3.upper() == "RANDOM ACCESS MEMORY":
        print("Correct!")
        score += 1
    else:
        print("Incorrect!")

    answer4 = input("what does CSS stand for? ")
    if answer4.upper() == "CASCADING STYLE SHEET":
        print("correct!")
        score += 1
    else:
        print("Incorrect!")
    answer5 = input("what does ROM stand for? ")
    if answer5.upper() == "READ ONLY MEMORY":
        print("Correct!")
        score += 1
    else:
        print("Incorrect!")

    print(f'You got {score} questions correct!')
    print("You got " + str((score / 5) * 100) + "%")