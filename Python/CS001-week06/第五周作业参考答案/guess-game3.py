#guess-game3.py
import random

def randomanswer(num):
#生成num个随机的不重复数字
    seeds=list(range(10))
    answer=""
    for i in range(num):
        x=random.randrange(0,10-i)
        answer=answer+str(seeds[x])
        seeds.remove(seeds[x])
    return answer

def countAB(x,y,num):
#统计答对情况
    countA,countB=0,0
    for j in range(num):
        if x[j]==y[j]:
            countA=countA+1
        elif x[j] in y:
            countB=countB+1
    print(countA,"A",countB,"B")
    return countA,countB

#主程序
level=int(input("How many digits? "))
y=randomanswer(level)
print("Hi! We have generated the answer. You have 10 chances to guess.")
for i in range(10):
    x=input("What is your guess #"+str(i+1)+"? ")
    A,B=countAB(x,y,level)
    if A==level:
        print("Bingo! You are a genius!")
        break
if A!=level:
    print("Sorry, the answer is "+str(y))
