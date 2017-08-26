#guess.py
import random
x=random.randrange(0,100)
for i in range(7):
    guess=int(input("[0,99] What is your guess #"+str(i+1)+"? "))
    if guess==x:
        print("Bingo! You are a genius!!")
        break
    elif guess<x:
        print("Your guess is too small")
    else:
        print("Your guess is too big")
if guess!=x:
    print("Sorry! The answer is",x)
