def mymin(x):
    if len(x)==1:
        return x[0]
    else:
        m=mymin(x[1:])
        if x[0]<m:
            return x[0]
        else:
            return m

print(mymin([3,5,7,2,4,6,0,1,2]))
print(mymin([10,9,8,7,6,1,2,3,4,5]))
