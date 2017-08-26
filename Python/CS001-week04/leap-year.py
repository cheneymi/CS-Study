#leap-year.py
y=int(input("What year is it? "))
if (y % 100 !=0 and y % 4 ==0) or (y % 400 ==0):
    print(y,"is a leap year.")
else:
    print(y,"is not a leap year.")
    
