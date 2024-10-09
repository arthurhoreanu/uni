import socket
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM) #AF_INET - adress family internet (IP 4)
#SOCK_DGRAM - UDP/SMS
#TCP - call
s.sendto(b"Arthur Horeanu si Alexia Voina",("193.231.20.76",7777))