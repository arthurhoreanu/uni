import socket
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("193.231.20.76",5556))
s.send(b"Salut!")
print(s.recv(10))
s.close()