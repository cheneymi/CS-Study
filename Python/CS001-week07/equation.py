equation=input("Please input an equation\n")
num1,num2,tmp=0,0,0
factor,sign=1,1
for i in equation:
    if i=="=":
        num2+=factor*sign*tmp
        tmp=0
        factor,sign=-1,1
    elif i=="+":
        num2+=factor*sign*tmp
        tmp=0
        sign=1
    elif i=="-":
        num2+=factor*sign*tmp
        tmp=0
        sign=-1
    elif ord(i)>=48 and ord(i)<=57:
        tmp=tmp*10+ord(i)-48
    elif ord(i)>=97 and ord(i)<=122:
        x=i
        if tmp==0:
            tmp=1
        num1+=factor*sign*tmp
        tmp=0

num2+=factor*sign*tmp
print(x,"=",-num2/num1)
