def duck(n):
    if n == 7:
        print(7,2,0)
        return 2
    else:
        x = duck(n+1)
        print(n,x+2,x)
        return (x+1)*2

print(duck(1))
