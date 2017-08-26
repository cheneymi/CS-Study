#费马大定理,又被称为“费马最后的定理”,由 17 世纪法国数学家皮耶·德·费玛提出。
#他断言当整数n >2时,关于x, y, z的方程 xn + yn = zn 没有正整数解。

isfound=False
n=int(input('Enter a number(above 2):'))
r=int(input('Enter another number:'))
for x in range(1,r):
     for y in range(x,r):
         for z in range(y,r):
             if x**n+y**n==z**n:
                 print(x,y,z)
                 isfound=True
                 continue
if isfound==False:
     print('Sorry,no equals.Try again.')
