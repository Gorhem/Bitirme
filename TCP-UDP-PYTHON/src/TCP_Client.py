import socket
import time

socket.setdefaulttimeout(2)

sckt = socket.socket()

host = socket.gethostname()

port = 5555

sckt.connect((host,port))

request = input("myrequest: ")

while request!="Exit":
    sender = bytes(request,"utf-8")
    sckt.send(sender)
    if request!="File":
        received = sckt.recv(1024).decode("utf-8")
        print(received)
    else:
        filenamebt = sckt.recv(1024)
        print(filenamebt.decode("utf-8"))
        newfilename = "tcptext1.mp4"
        with open(newfilename,'wb') as newfile:
            start_time = time.time()
            while True:
                try:
                    writedata= sckt.recv(1024)
                    newfile.write(writedata)
                except socket.timeout:
                    break
            newfile.close()
            print("time: ",(time.time()-start_time-2.0 ) )
    request = input("myrequest: ")
sender= bytes(request, "utf-8")
sckt.send(sender)
sckt.close()

