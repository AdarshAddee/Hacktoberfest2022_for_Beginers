// Github username: RazerAds
// Aim: To set up a UDP server
// Date: 23/10/22

// start coding

from socket import*
serv_addr= "192.168.161.129"
serv_port=7000
serv_sock=socket(AF_INET,SOCK_DGRAM)
serv_sock.bind((serv_addr,serv_port))
print(("The server is ready to receive"))
while 1:
	msg,client_addr = serv_sock.recvfrom(2048)
	print("Got message from",client_addr,"\n Message: ",msg)
	mod_msg=msg.upper()
	serv_sock.sendto(mod_msg,client_addr)
