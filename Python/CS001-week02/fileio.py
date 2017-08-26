#fileio.py
with open("wordlist.in","r") as fin:
    text=fin.read()
with open("result.out","w") as fout:
    fout.write(text)
    fout.write("\n\nThere are {0} letter 'e'".format(text.count("e")))
    fout.write("\n\nThere are {0} letter 'a'".format(text.count("a")))
    fout.write("\n\nThere are {0} letter 'i'".format(text.count("i")))
    fout.write("\n\nThere are {0} letter 'o'".format(text.count("o")))
    

