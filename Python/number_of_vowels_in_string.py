## github username:- pratham1729
## This is a function to get the number of vowels in a string
def number_of_vowels(x):
        c=0
        for i in x.lower():
                if i in ("a","e","i","o","u"):
                        c+=1
        return c

test=input("Enter your string:")

print(number_of_vowels(test))


