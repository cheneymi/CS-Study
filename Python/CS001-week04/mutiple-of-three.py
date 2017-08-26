#mutiple-of-three.py
x=int(input("Please give me a number: "))
if x % 3 == 0:
    print(x,"is a mutiple of 3")
elif x % 3 ==1:
    print(x,"is 1 plus a mutiple of 3")
else:
    print(x,"is 2 plus a mutiple of 3")
