x = 0
for i in range(1,10):
    if i % 2 == 0:
        x = x - 1/(2*i-1)
    else:
        x = x + 1/(2*i-1)
    if i == 100:
        print(i,x*4)
print(x*4)
