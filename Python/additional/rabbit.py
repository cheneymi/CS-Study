def rabbit(n):
    if n <=1:
        return 1
    else:
        return rabbit(n-2)*2

n = int(input('Enter a number:'))
print(rabbit(n))
