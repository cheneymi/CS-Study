#guess-game2.py
import random

digit=int(input("Enter a number:"))
def randomanswer(num):
#生成num个随机的不重复数字
    seeds=list(range(10))
    answer=""
    for i in range(num):
        x=random.randrange(0,10-i)
        answer=answer+str(seeds[x])
        seeds.remove(seeds[x])
    return answer

def countAB(x,y):
#统计答对情况
    countA,countB=0,0
    for j in range(digit):
        if x[j]==y[j]:
            countA=countA+1
        elif x[j] in y:
            countB=countB+1
    print(countA,"A",countB,"B")
    return countA,countB

#主程序
y=randomanswer(digit)
print("Hi! We have generated a ",digit,"-digit number. You have 10 chances to guess.")
for i in range(10):
    x=input("What is your guess #"+str(i+1)+"? ")
    A,B=countAB(x,y)
    if A==digit:
        print("Bingo! You are a genius!")
        break
if A!=digit:
    print("Sorry, the answer is "+str(y))
