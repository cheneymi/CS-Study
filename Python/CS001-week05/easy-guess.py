import random
hello=random.randint(0,9)
CORRECT=False
while not CORRECT:
    guess=int(input("[0,9]What is your guess? "))
    if guess<hello:
        print("Too small!")
    elif guess>hello:
        print("Too big!")
    else:
        print("Smart kid!")
        CORRECT=True
