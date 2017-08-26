for n in range(2,100):
    x=n
    while x!=1:
        print(str(x)+"-",end="")
        if x % 2 == 0:
            x=x//2
        else:
            x=x*3+1
    print(1)

        
    
