#  Github username: Rtarun3606k
#  Aim: python program to  find an amstrong number
#  Date: 10/7/2023




class colors:
    RESET = '\033[0m'
    RED = '\033[31m'
    GREEN = '\033[32m'
    YELLOW = '\033[33m'
    BLUE = '\033[34m'
    PURPLE = '\033[35m'
    CYAN = '\033[36m'
    WHITE = '\033[37m'


def amstrong():
    try:
        n = input("enter an number to fint weather its's amstrong number: ")
        n_leng = len(n)
        sum = 0
        for i in range(0,n_leng):
            n_index = n[i]
            n_index=int(n_index)
            cube = n_index**3 
            sum = sum + cube
        n=int(n)
        if sum == n:
            print(f"the enter number is an amrgrong number: {n}")
        else:
            print(f"the enterd number {n} is not eaual to the sum {sum} ")
    except Exception as e:
        print('Try again after some time')


if __name__ == "__main__":
    print( colors.RED + "what is amstrong number?" + colors.RESET)
    print(  colors.GREEN + "amstrong An Armstrong number (also known as a narcissistic number, plenary number, or a plus perfect number) \n  is a number that is equal to the sum of its own digits, each raised to the power of the number of digits. \n In other words, for a number with n digits, if the sum of the nth powers of its digits is equal to the number itself, then it is an Armstrong number. \n  For example, let's take the number 153: \n The number of digits in 153 is 3. \n The sum of the cubes of its digits is: 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153. \n Since the sum of the cubes of its digits is equal to the number itself, 153 is an Armstrong number."+ colors.RESET)

    amstrong()

# amstrong An Armstrong number (also known as a narcissistic number, plenary number, or a plus perfect number) is a number that is equal to the sum of its own digits, each raised to the power of the number of digits.

# In other words, for a number with n digits, if the sum of the nth powers of its digits is equal to the number itself, then it is an Armstrong number.

# For example, let's take the number 153:

# - The number of digits in 153 is 3.
# - The sum of the cubes of its digits is: 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153.

# Since the sum of the cubes of its digits is equal to the number itself, 153 is an Armstrong number.