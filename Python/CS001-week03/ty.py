import time

#TEXT="Hello everybody! I have to tell you I love programming."
TEXT="qwertyuiopasdfghjklzxcvbnm"

start=time.time()
s=input("Please type:"+TEXT+"\n")
end=time.time()
print("You took "+str(end-start)+" seconds to type the above.")
print("The matching result is "+ str(s==TEXT))
