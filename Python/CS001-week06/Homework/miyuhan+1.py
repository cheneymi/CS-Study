def first(x):
    if len(x) == 2:
        if x[1] > x[0]:
            return x[1]
        else:
            return x[0]
    else:
        a = x[len(x)-1]
        x.pop()
        b = first(x)
        if a > b:
            return a
        else:
           return b 
def second(x):
    if len(x) == 2:
        if x[1] > x[0]:
            return x[0]
        else:
            return x[1]
    else:
        a = x[len(x)-1]
        x.pop()
        b = first(x)
        if a > b:
            return b
        else:
            c = second(x)
            if a < c:
                return c
            else:
                return a

print(second([1,2,3,4,5]))
print(second([10,9,8,7,6]))
