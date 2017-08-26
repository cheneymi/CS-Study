#discount2.py
def money(n):
    if n<10:
        return n*30
    else:
        return n*25

n=int(input("How much mantis shrimp? "))
print("The total payment is",money(n),"RMB.")
