import socket
import datetime

sckt = socket.socket()

host = socket.gethostname()

port = 5555

sckt.bind((host,port))

sckt.listen(1)

client,address = sckt.accept()

while True:
    mydata=client.recv(1024)
    Datastring = mydata.decode("utf-8")
    if Datastring == "Ping":
        sender= bytes("Pong","utf-8")
        client.send(sender)
    if Datastring== "Timestamp":
        mytime= datetime.datetime.now().strftime('%H:%M:%S %Y/%m/%d')
        sender= bytes(mytime,"utf-8")
        client.send(sender)
    if Datastring == "Exit":
        client.close()
        break
    if Datastring== "File":
        filename ="tcptest.mp4"
        sender= bytes(filename, "utf-8")
        client.send(sender)
        myfile= open(filename,'rb')
        parts= myfile.read(1024)
        while(parts):
            client.send(parts)
            parts= myfile.read(1024)
        myfile.close()

