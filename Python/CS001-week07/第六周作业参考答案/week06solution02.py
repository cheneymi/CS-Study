def sumsquared(a):
    if a==0:
        return 0
    else:
        return a*a+sumsquared(a-1)

n=int(input("n = "))
print(sumsquared(n))
