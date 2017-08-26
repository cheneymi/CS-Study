def nsum(n):
    if n == 1:
        return 1
    elif n <= 0:
        print('Sorry, not avalible!!!!!!!!!!!!!!!!!!')
        return ''
    else:
        return n+nsum(n-1)

n=int(input('Enter a number:'))
print(nsum(n))
