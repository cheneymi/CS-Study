#decodeASCII.py
text=input("Please enter the code:")

#basic method
words=text.split(" ")
for word in words:
    print(chr(int(word)),end="")

#pythonic method
print("".join(list( map(chr,list(map(int,text.split(" ")))))))
