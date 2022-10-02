### palindrome
### /ˈpalɪndrəʊm/
### a word, phrase, or sequence that reads the same backwards as forwards, e.g. madam or nurses run.

print("[Palindrome Checker]")
print("Example: deified, eve, wow, noon, zaramaraz")


def check_palindrome(input):
    if len(input) == 0:
        print("Please, give the proper input")
        exit()
    x = input.lower()
    text = ""
    for i in range(len(x)): 
        if x[i].isalnum(): text = text + x[i]
    return text == text[::-1]


test = input("Is a palindrome word: ")
print(check_palindrome(test))