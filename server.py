import socket

s = socket.socket()
host = socket.gethostname()
port = 8888

s.bind((host,port))
s.listen(1)

while True:
	c,addr = s.accept();
	msg = c.recv(1024)
	print msg
