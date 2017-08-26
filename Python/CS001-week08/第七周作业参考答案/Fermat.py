LIMIT_N=10
MAX=int(input("what range? "))
count=0
for n in range(3,LIMIT_N+1):
    for a in range(1,MAX+1):
        for b in range(a,MAX+1):
            for c in range(b,MAX+1):
                if a**n+b**n==c**n:
                    count+=1
                    print(a,b,c)
print("Total count:",count)
