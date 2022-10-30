## github username:- jhonatasmatos
# This is a simple program to describe if the number typed is positive or negative
"""
Step to run:
prerequisite : python of version 3 or above should be installed in your system
1. copy-Paste or download this file in code editor.
2. run the file.
3. Type a number.
"""

number = float(input("Type a number\n"))

if number > 0:
    print(f"Number {number} is positive")
elif number < 0:
    print(f"Number {number} is negative")
else:
    print(f"Number {number} is neutral")