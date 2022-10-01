# Contributed by AnuragVats007

# Blackjack Capstone Game
import random as r
def BlackJack():
    print()
    deck = [11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10]
    comp_cards = []
    your_cards = []
    r.shuffle(deck)
    comp_cards.append(r.choice(deck))
    r.shuffle(deck)
    comp_cards.append(r.choice(deck))
    r.shuffle(deck)
    your_cards.append(r.choice(deck))
    r.shuffle(deck)
    your_cards.append(r.choice(deck))
    sum = 0
    comp_sum = 0
    for i in your_cards:
        sum += i
    for i in comp_cards:
        comp_sum += i
    print(f"your cards: {your_cards}")
    print(f"computer's first card: {comp_cards[0]}")
    fl = True
    while fl:
        ch = input("Type 'y' to get another card or type 'n' to pass: ")
        if ch=='y':
            r.shuffle(deck)
            your_cards.append(r.choice(deck))
            sum+=your_cards[2]
            print(f"your cards: {your_cards}")
        else:
            fl = False
        if sum>21:
            fl = False
    if comp_sum<17:
        r.shuffle(deck)
        comp_cards.append(r.choice(deck))
        comp_sum+=comp_cards[2]
    print(f"Your cards: {your_cards}")
    print(f"Computer's cards: {comp_cards}")
    print(f"Your total: {sum}")
    print(f"Computer's total: {comp_sum}")
    
    if sum>21:
        print("\n >>> YOU LOSE!!!")
    elif comp_sum>21:
        print("\n >>> YOU WON!!!")
    elif sum<comp_sum:
        print("\n >>> YOU LOSE!!!")
    elif sum>comp_sum:
        print("\n >>> YOU WON!!!")
    else:
        print("\n >>> ITS A DRAW!!!")

def main():
    flag = True
    while flag:
        choice = input("Do you want to play BlackJack/21 ?(y/n): ")
        if choice=='y':
            BlackJack()
        else:
            flag = False

main()
