#检验哥德巴赫猜想
def isPrime(a):
    if a<2:
        return False
    for i in range(2,a):
        if a % i == 0:
            return False
    return True

#输入猜想检验的范围n
x=int(input("Please input a number: "))

#建立质数列表
primelist=[2]
for i in range(3,x,2):
    if isPrime(i):
        primelist.append(i)

#用枚举法检验猜想 
for n in range(6,x+1,2):
    for i in range(3,x):
        if (i in primelist) and ((n-i) in primelist):
            print(n,"=",i,"+",n-i)
            break


