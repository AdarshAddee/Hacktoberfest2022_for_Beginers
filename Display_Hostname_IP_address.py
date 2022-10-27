'''
  Github username:https://github.com/vishwjeet-ujgare
  Aim:There are many ways to find the hostname and IP address of a local machine. Here is a simple method to find the hostname and IP address using python code. 
  Date:27/10/2022
  start coding
'''
# Importing socket library
import socket

# Function to display hostname and
# IP address


def get_Host_name_IP():
	try:
		host_name = socket.gethostname()
		host_ip = socket.gethostbyname(host_name)
		print("Hostname : ", host_name)
		print("IP : ", host_ip)
	except:
		print("Unable to get Hostname and IP")


# Driver code
get_Host_name_IP() # Function call

# This code is contributed by "Sharad_Bhardwaj".
