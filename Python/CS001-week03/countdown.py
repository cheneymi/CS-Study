import turtle
import time
p=turtle.Turtle()
for i in range(10,0,-1):
    p.write(i,font=("Arial", 50, "normal"))
    time.sleep(1)
    p.clear()
p.write("BLAST OFF!!",font=("Arial", 50, "normal"))

