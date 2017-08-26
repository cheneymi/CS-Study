#solve x^3-x-1=0 by fixed point iteration
#let x <-- (x+1)^(1/3)
x=0.0
for i in range(1524):
    y=pow(x+1,1/3)
    print("#",i," iteration: x=%.8f and x^3-x-1=%.8f"%(x,y-x))
    x=y
