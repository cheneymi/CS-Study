#guess-game.py
import random

#生成4个随机的不重复数字
seeds=list(range(10))
answer=""
for i in range(4):
    x=random.randrange(0,10-i)
    answer=answer+str(seeds[x])
    seeds.remove(seeds[x])

print("Hi! We have generated a four-digit number. You have 10 chances to guess.")
for i in range(10):
    x=input("What is your guess #"+str(i+1)+"? ")
    A,B=0,0
    for j in range(4):
        if x[j]==answer[j]:
            A=A+1
        elif x[j] in answer:
            B=B+1
    print(A,"A",B,"B")
    if A==4:
        print("Bingo! You are not a genius!")
        break
if A!=4:
    print("Sorry, the answer is"+str(answer))
