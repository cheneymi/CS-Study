def mcd(a,b):
    d = 1
    for i in range(2,a):
        if a % i ==0:
            if b % i ==0:
                a = a // i
                b = b // i
                d = i
                break
    if d == 1:
        return 1
    else:
        return d * mcd(a,b)

a = int(input('Enter a number:'))
b = int(input('Enter a number:'))
print(mcd(a,b))
