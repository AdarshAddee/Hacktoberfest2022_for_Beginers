//hemrajmalhi
//To create a program that takes a number and generate a random password length of that number
//12-10-2022

//code 

import random
passlen = int(input("enter the length of password"))
s="abcdefghijklmnopqrstuvwxyz01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()?"
p =  "".join(random.sample(s,passlen ))
print (p)
