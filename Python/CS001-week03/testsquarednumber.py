import random

MIN=21
MAX=50
for i in range(MIN,MAX):
    print(i,"*",i,"=",i**2)

for i in range(5):
    num=random.randint(MIN,MAX)
    x=input("What is "+str(num)+"*"+str(num)+"?\n")
    print(str(num)+"*"+str(num)+"="+str(num**2))
    
