import socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("193.231.20.76", 6969))
s.send(b"Dreifachstecker!")
msg = s.recv(10)
print(msg.decode())
s.close()