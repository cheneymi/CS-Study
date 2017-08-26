def countood(a):
    count=0
    for x in a:
        count=count+1
    return count

t=[1,2,3,4,5,11,12,13,14,15]
print(countodd(t))
t.remove(5)
print(countodd(t))
t.remove(3)
print(countodd(t))
t=t+[9,9,9]
print(countodd(t))
