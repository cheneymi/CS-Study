MAX=51
for a in range(1,MAX):
    for b in range(a,MAX):
        for c in range(b,MAX):
            if a*a+b*b==c*c:
                print(a,b,c)
