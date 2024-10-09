import socket
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.sendto(b"espressooo!!!",("127.0.0.1",5555))