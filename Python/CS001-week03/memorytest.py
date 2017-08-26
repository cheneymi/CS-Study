#reading 
import turtle
import time
import random

#number per line
npl=7
#time on the screen
t=1.0
number="".join([str(random.randint(0,9)) for i in range(npl)])
turtle.write(number, align="center", font=("Arial",50,"normal"))
time.sleep(t)
turtle.clear()
turtle.bye()
test=input("Please input the number just shown:")
print("Please check the number just shown:"+number)
    

