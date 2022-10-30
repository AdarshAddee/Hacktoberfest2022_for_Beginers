## github username:- jhonatasmatos
# This is a simple program to check if the letter is vowel or not
"""
Step to run:
prerequisite : python of version 3 or above should be installed in your system
1. copy-Paste or download this file in code editor.
2. run the file.
3. Type a letter.
"""

letter = input("Type a letter\n")
vogals = {"a", "e", "i", "o", "u"}

if letter in vogals:
    print("Letter is vowel")
else:
    print("Letter is consonant")