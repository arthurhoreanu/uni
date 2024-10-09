import socket
s=socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
IP = "193.231.20.76"
Port = 7777
s.sendto(b'Arthur Horeanu si Alexia Voina',(IP, Port))
data, addr = s.recvfrom(1024)
print(f"Received message from {addr}: {data.decode()}")