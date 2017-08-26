import time
import sys
def fibonacci(n):
    if n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        return fibonacci(n-1)+fibonacci(n-2)

sys.setrecursionlimit(2000)
n=int(input('Enter a number:'))
for i in range(1,n+1):
    start=time.time()
    x=fibonacci(i)
    end=time.time()
    print(i,x,str(end-start))
