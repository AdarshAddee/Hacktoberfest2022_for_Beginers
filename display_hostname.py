#printing Hostname and IP using socket module
import socket
 
# Function to display hostname and
# IP address
 
def get_Host_name_IP():
    try:
        host_name = socket.gethostname()
        host_ip = socket.gethostbyname(host_name)
        print("Hostname :  ", host_name)
        print("IP : ", host_ip)
    except:
        print("Unable to get Hostname and IP")

 
get_Host_name_IP() 
