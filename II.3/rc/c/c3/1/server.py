import socket
s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(("0.0.0.0",6969))
s.listen()
cs,addr=s.accept() #cs = client socket
print(addr)