import sys

def mysum(n):
    if n==1:
        return 1
    else:
        return n+mysum(n-1)

sys.setrecursionlimit(2000)
print(mysum(1))
print(mysum(3))
print(mysum(10))
print(mysum(100))
print(mysum(1000))
