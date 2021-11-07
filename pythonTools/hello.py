#!/usr/bin/python 

import socket

print("Hello Networ Scanenr");


sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = "65.61.137.117"
port = 80

def portscanner(port):
	if sock.connect_ex((host, port)):
		print "Port %d is closed" % (port)
	else:
		print "Port %d is open" % (port)

portscanner(port)




