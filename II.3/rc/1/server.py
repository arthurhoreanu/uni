import socket
s=socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(("0.0.0.0", 5555)) #always "0.0.0.0"!!!
print(s.recvfrom(20))