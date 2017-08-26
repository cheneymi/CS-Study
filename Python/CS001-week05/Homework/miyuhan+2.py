n=2
where=int(input("Please enter a number:"))
while n<where:
    PRIME = True
    i=2
    while i<n:
        if n % i == 0:
            PRIME=False
            print(n,"=",i,"*",n//i)
            break
        i=i+1
    if PRIME:
        print(n, " is a prime number.")
    n=n+1
