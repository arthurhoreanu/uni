import socket
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
m="GET / HHTP/1.1\n\n"
s.connect(("google.com", 80))
s.send(str.encode(m))
print(s.recv(1000))