#Github username: Hithesh1334
#Aim: To print hostname and the ip address  
#Date: 18/oct/2022

import socket  

hostName  = socket.gethostname() #getting the hostname
ip_address = socket.gethostbyname(hostName) #getting the ip address
 
print(f'Hostname: {hostName}')
print(f'Ip address: {ip_address}')


''' 
#using command line argument 

import os 
try: 
    os.system('cmd /k "whoami"')
    os.system('cmd /k "ipconfig"')
except:
    print("could not execute")

'''