import time

for i in range(9):
    LIMIT=10**i
    start=time.time()
    for j in range(LIMIT):
        x=1
    end=time.time()
    print(str(LIMIT)+" loops take "+str(end-start)+" seconds")
    
