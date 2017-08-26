def nsquare(n):
    if n == 0:
        return 0
    else:
        return n*n+nsquare(n-1)
s = int(input("Enter a number:"))
print(nsquare(s))
