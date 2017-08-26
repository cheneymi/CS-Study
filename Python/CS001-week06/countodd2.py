def countodd2(a):
    if a==[]:
        return 0
    else:
        return a[0] % 2 + countodd2(a[1:])

t=[1,2,3,4,5,11,12,13,14,15]
print(countodd2(t))
t.remove(5)
print(countodd2(t))
t.remove(3)
print(countodd2(t))
t=t+[9,9,9]
print(countodd2(t))
