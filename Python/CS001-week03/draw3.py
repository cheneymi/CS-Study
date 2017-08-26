from turtle import *
size=int(input("size:"))
angle=int(input("angle:"))
colormode(255)
color((127, 127, 127),(255,255,0))
begin_fill()
while True:
     forward(size)
     left(180-angle)
     if abs(pos()) < 1:
        break
end_fill()
done()
