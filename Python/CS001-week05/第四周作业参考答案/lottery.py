import random
seeds=list(range(1,34))
red=[]
for i in range(6):
    x=random.randrange(0,33-i)
    red.append(seeds[x])
    seeds.remove(seeds[x])

blue=random.randint(1,16)

print("RED: ",red,"\nBLUE:",blue)
