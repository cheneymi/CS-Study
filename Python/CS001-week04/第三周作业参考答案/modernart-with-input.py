#modernart-with-input.py
import turtle
import random

#只需要修改以下这一句为标准输入即可
NUM=int(input("How many rectangles? "))
XMAX=300
YMAX=400

for i in range(NUM):
    p=turtle.Turtle()
    p.hideturtle()
    p.speed("fastest")
    rcolor=random.choice(["grey","blue","yellow"])
    p.pen(pencolor=rcolor,pensize=3)
    #p.pen(pencolor="grey",pensize=3)
    x1=random.randrange(-XMAX,XMAX)
    y1=random.randrange(-YMAX,YMAX)
    x2=random.randrange(-XMAX,XMAX)
    y2=random.randrange(-YMAX,YMAX)
    p.penup()
    p.goto(x1,y1)
    p.pendown()
    p.goto(x1,y2)
    p.goto(x2,y2)
    p.goto(x2,y1)
    p.goto(x1,y1)
    
