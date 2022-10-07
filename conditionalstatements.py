#CONDITIONAL STATEMENTS

def drink(money):
if money >= 2:
return "You've got yourself a drink!"
else:
return "No drink for you!"

print(drink(3))
print(drink(1))

def alcohol(age,money):
if (age >= 21) and (money >= 5):
return "We're getting a drink!"
elif (age >= 21) and (money < 5):
return "Come back with more money."
elif (age < 21) and (money >= 5):
return "Nice try, kid!"
else:
return "You're too poor and too young!"

print(alcohol(21,5))
print(alcohol(21,4))
print(alcohol(20,5))
print(alcohol(20,4))