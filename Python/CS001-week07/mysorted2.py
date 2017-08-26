def mysorted(x):
    y=x[:]
    z=[]
    for i in range(len(y)):
        m=min(y)
        y.remove(m)
        z.append(m)
    return z

print(mysorted([3,5,7,2,4,6,0,1,2]))
print(mysorted([10,9,8,7,6,1,2,3,4,5]))
