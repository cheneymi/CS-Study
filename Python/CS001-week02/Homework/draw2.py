from turtle import *
from random import randint
length = int(input('Please enter a length:'))
angle = int(input('Please enter an angle:'))
colormode(255)
color((111, 111, 111),(255,255,0))
begin_fill()
while True:
    forward(length)
    if randint(1, 2) == 1:
        left(angle)
    else:
        right(angle)
    if abs(pos()) < 1:
        break
end_fill()
done()
