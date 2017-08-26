#prime1.py
n=int(input("Please input a number: "))
PRIME = True
for i in range(2,n):
    if n % i == 0:
        PRIME=False
        print(n,"=",i,"*",n//i)
        break
if PRIME:
    print(n,"is a prime number.")

