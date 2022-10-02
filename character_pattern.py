# Python program to generate a character pattern

# Github Username : aritroo

#Example Output is given below :-
# Enter the number of rows : 5
# A 
# B B
# C C C
# D D D D
# E E E E E



def character(n):
	
	num = 65

	for i in range(0, n):
	
		for j in range(0, i+1):
		
			ch = chr(num)
		
			print(ch, end=" ")
	
		num = num + 1
	
		print("\r")

n = int(input("Enter the number of rows : "))
character(n)
