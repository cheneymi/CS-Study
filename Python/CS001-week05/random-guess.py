import random
x=random.randint(0,9)
CORRECT=False
while not CORRECT:
    guess=random.randint(0,9)
    print("The robot's guess is",guess)
    if guess<x:
        print("Too small!")
    elif guess>x:
        print("Too big!")
    else:
        print("Smart robot!")
        CORRECT=True

