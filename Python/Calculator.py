#purpose: to calculate two given numbers by the user
#updates:
    #1. 2022-10-04 22:17:04: created the project
    #2. 2022-10-04 00:27:55: completed project




print("----------------")
print("created by: ")
print("https://github.com/ChefYeshpal")
print("for: hacktober")
print("----------------")


#adds two numbers
def add(x, y):
    return x + y

#subtracts two numbers
def subtract(x, y):
    return x - y

#multiplies two numbers
def multiply(x, y):
    return x * y

#divides two numbers
def divide(x, y):
    return x / y


print("----------------")
#imports todays date and time
import datetime
t = datetime.datetime.now()
print(t)
print("----------------")


print("welcome to my attempt to create a calculator from python!!!")
print("what would you like to do today?")


print("----------------")
print("Select operation.")
print("1.Add")
print("2.Subtract")
print("3.Multiply")
print("4.Divide")
print("----------------")


while True:
    choice = input("Enter choice(1/2/3/4): ")

    print("----------------")

    if choice in ('1', '2', '3', '4'):
        num1 = float(input("please first number: "))
        num2 = float(input("please second number: "))

        if choice == '1':
            print(num1, "+", num2, "=", add(num1, num2))

        elif choice == '2':
            print(num1, "-", num2, "=", subtract(num1, num2))

        elif choice == '3':
            print(num1, "*", num2, "=", multiply(num1, num2))

        elif choice == '4':
            print(num1, "/", num2, "=", divide(num1, num2))
        break
    else:
        print("Invalid Input")

print("----------------")

