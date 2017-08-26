import turtle
import random

NUM=25
XMAX=400
YMAX=400
'''
for i in range(NUM):
    x=random.randrange(-XMAX,XMAX)
    y=random.randrange(-YMAX,YMAX)
    turtle.goto(x,y)
'''    
colors=["grey","brown","orange","yellow","blue","red"]
rcolor=random.choices(colors,k=2)
turtle.color(rcolor[0],rcolor[1])
turtle.begin_fill()
for i in range(NUM):
    x=random.randrange(-XMAX,XMAX)
    y=random.randrange(-YMAX,YMAX)
    turtle.goto(x,y)
turtle.end_fill()
