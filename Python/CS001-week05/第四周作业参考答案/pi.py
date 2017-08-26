#pi.py
num=0
factor=1
for i in range(10000000):
    num = num + factor/(i+i+1)
    factor=-factor
print(num*4)
