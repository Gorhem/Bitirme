import socket
import datetime

sckt = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

host = socket.gethostname()

port = 5558

sckt.bind((host,port))

while True:
    request,client = sckt.recvfrom(1024)
    req=request.decode("utf-8")
    if req == "Ping":
        sender = bytes("Pong", "utf-8")
        sckt.sendto(sender, client)
    if req == "Timestamp":
        mytime = datetime.datetime.now().strftime('%H:%M:%S %Y/%m/%d')
        sender = bytes(mytime, "utf-8")
        sckt.sendto(sender, client)
    if req == "Exit":
        sckt.close()
        break
    if req =="File":
        filename = "udptest.mp4"
        sender = bytes(filename, "utf-8")
        sckt.sendto(sender, client)
        myfile = open(filename, 'rb')
        parts = myfile.read(1024)
        while (parts):
            sckt.sendto(parts, client)
            parts = myfile.read(1024)
        myfile.close()


