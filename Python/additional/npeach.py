def peach(n):
    if n == 10:
        return 1
    else:
        return (peach(n+1)+1)*2

print(peach(1))
