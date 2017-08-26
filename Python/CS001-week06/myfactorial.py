def mfactorial(n):
    if n==1 or n==0:
        return 1
    else:
        return n * mfactorial(n-1)

print(mfactorial(0))
print(mfactorial(1))
print(mfactorial(3))
print(mfactorial(5))
print(mfactorial(10))
print(mfactorial(100))
