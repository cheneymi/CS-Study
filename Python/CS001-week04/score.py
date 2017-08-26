#score.py
x=float(input("What is your score? [0-100] "))
if x>=90.0:
    grade="A"
elif x>=80.0:
    grade="B"
elif x>=70.0:
    grade="C"
elif x>=60.0:
    grade="D"
elif x>=50.0:
    grade="E"
else:
    grade="F"
print("Your grade is",grade)
