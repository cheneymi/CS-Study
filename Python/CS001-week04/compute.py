#compute.py
x=0
for i in range(100):
    if i % 2 == 1:
        x=x+i*i
    else:
        x=x-i*i
print(x)
