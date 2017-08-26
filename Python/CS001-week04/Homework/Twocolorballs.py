#Two Color Balls
from random import randint
r = []
b = randint(1,17)
while True:
    s = False
    n = randint(1,34)
    for i in range(len(r)):
        if r[i] == n:
            s = True
            break
    if s == False:
        r.append(n)
    if len(r) == 6:
        break
print(r,b)
