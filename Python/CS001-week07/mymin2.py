def mymin(x):
    m=x[0]
    for i in x[1:]:
        if i<m:
            m=i
    return m

print(mymin([3,5,7,2,4,6,0,1,2]))
print(mymin([10,9,8,7,6,1,2,3,4,5]))
