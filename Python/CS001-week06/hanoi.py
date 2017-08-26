def hanoi(n,x,y,z):
    if n==1:
        print("Move disk",1,"from",x,"to",z)
    else:
        hanoi(n-1,x,z,y)
        print("Move disk",n,"from",x,"to",z)
        hanoi(n-1,y,x,z)

hanoi(3,"A","B","C")
