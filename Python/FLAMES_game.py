def Flames(name1,name2):
    namestr = name1 + name2

    for c in namestr:
        if namestr.count(c) != 1:
            # counting common letters
            namestr = namestr.replace(c,"")

    # The common letters are replaced by blankspace therefore namestr has only remaining letters

    print("FLAMES....")
    print("F = Friend \nL = Love \nA = Affection \nM = Marriage \nE = Enemy \nS = Siblings \n\n")
    

    number = len(namestr) % 6
    # number to move through FLAMES
    rel = ""

    if number == 1:
        rel += "Friends"
    elif number == 2:
        rel += "Love"
    elif number == 3:
        rel += "Affection"
    elif number == 4:
        rel += "Marriage"
    elif number == 5:
        rel += "Enemy"
    elif number == 0:
        rel += "Siblings"
    else:
        pass

    return rel

n1 = input("Enter your name : ").upper()
n2 = input("Enter name of your crush : ").upper()
print(f"Your Relationship is : {Flames(n1,n2)}")
