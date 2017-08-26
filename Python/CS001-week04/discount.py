#discount.py
n=int(input("How much mantis shrimp? "))
if n<10:
    money=n*30
else:
    money=n*25
print("The total payment is",money,"RMB.")
