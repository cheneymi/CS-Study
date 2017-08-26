from turtle import *
color("#FF0000", "#00FF00")
begin_fill()
while True:
    forward(300)
    right(170)
    if abs(pos()) < 1:
        break
end_fill()
done()



    
