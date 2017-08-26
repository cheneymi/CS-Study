#prime3.py
primelist=[]
for n in range(2,1000):
    PRIME = True
    for i in range(2,n):
        if n % i == 0:
            PRIME=False
            break
    if PRIME:
        primelist.append(n)
print(primelist)

