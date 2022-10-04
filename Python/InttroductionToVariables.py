# Variables are containers for storing data values.
# Python has no command for declaring a variable.
# A variable is created the moment you first assign a value to it.


x = 12    # X is of integer type.
y = "Nitesh"  # y is of string type.
print(x)
print(y)

# If you want to specify the data type of a variable, this can be done with casting.

x = str(51)    # x will be '51'
y = int(2022)    # y will be 2022
z = float(45)  # z will be 45.0


# You can get the data type of a variable with the type() function.

x = 12
y = "Robin"
print(type(x))
print(type(y))

# String variables can be declared either by using single or double quotes:
st = 'Hello'
# is same as 
st = "Hello"

#In Python variables are case sensitive.
A = "Tech"
a = "Technology"
# A and a both are diffrent

# A variable can have a short name (like x and y) or a more descriptive name (age, carname, total_volume). Rules for Python variables:
# A variable name must start with a letter or the underscore character
# A variable name cannot start with a number
# A variable name can only contain alpha-numeric characters and underscores (A-z, 0-9, and _ )
# Variable names are case-sensitive (age, Age and AGE are three different variables)

myvar = "Mishra"
my_var = "Mishra"
_my_var = "Mishra"
myVar = "Mishra"
MYVAR = "Mishra"
myvar2 = "Mishra"

#In Pyhton You can assign values to multiple variables in one line:

x, y, z = "Orange", "Banana", "Cherry"
print(x)
print(y)
print(z)


# And you can assign the same value to multiple variables in one line:
x = y = z = "Orange"
print(x)
print(y)
print(z)