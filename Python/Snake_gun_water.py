import random
a=".......SNAKE/WATER/GUN......."
print(a.center(100))
winning=0
loosing=0


def chosen(comp,user):
    r=True
    if comp=="s":
        if user=="g":
            return r
        elif user=="w":
            r=False
            return r
        else:
            return None
    elif comp=="g":
        if user=="s":
            r=False
            return r
        elif user=="w":
            return r
        else:
            return None
    elif comp=="w":
        if user=="s":
            return r
        elif user=="g":
            r=False
            return r
        else:
            return None
print("How many turns u want to bet! :-")
n=int(input())
for _ in range(n):
    print("Choose your option")
    print("'s' for snake")
    print("'g' for gun")
    print("'w' for water:")
    user=input()
    compScore=random.randint(1,3)
    if compScore==1:
        comp= "s"
    elif compScore==2:
        comp= "g"
    elif compScore==3:
        comp="w"
    print("computer chose :"+comp)
    if user=="s" or user=="g" or user=="w":
         a= chosen(comp,user)
         if a==None:
            print("Game tie🤗")
            print(".....................................")

         elif a==True:
            print("U win🥳🥳")
            print(".....................................")
            winning+=1
         elif a==False:
            print("U lose!🙄")
            print(".....................................")
            loosing+=1
    else:
         print("Chosen option not available")
         print("...................")
print("************************************************************************")
print("YOUR RESULT:-")
if winning>loosing:
    print("Congratulations you won!!!")
    print("your points:- "+str(winning))
    print("computer points:- "+str(loosing))


elif loosing > winning:
    print("!!!you lose!!!")
    print("your points:- " + str(winning))
    print("computer points:- " + str(loosing))


else:
    print("Game tie")
    print("your points:- " + str(winning))
    print("computer points:- " + str(loosing))







