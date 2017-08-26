MAX=51
for a in range(1,MAX):
    for b in range(a,MAX):
        c=pow(a*a+b*b,0.5)
        if c==round(c):
            print(a,b,round(c))
