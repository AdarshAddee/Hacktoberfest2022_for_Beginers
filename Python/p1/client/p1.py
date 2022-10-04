import socket
import pickle

HEADERSIZE = 10

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((socket.gethostname(), 6969))

while True:
    full_msg = b''
    new_msg = True
    while True:
        msg = s.recv(16)
        if new_msg:
            print("new msg len:",msg[:HEADERSIZE])
            msglen = int(msg[:HEADERSIZE])
            new_msg = False

        print(f"full message length: {msglen}")

        full_msg += msg

        print(len(full_msg))

        if len(full_msg)-HEADERSIZE == msglen:
            print("full msg recvd")
            print(full_msg[HEADERSIZE:])
            print(pickle.loads(full_msg[HEADERSIZE:]))
            new_msg = True
            full_msg = b""