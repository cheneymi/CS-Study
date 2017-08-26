t=[[1]]
for i in range(4):
    print(t[i])
    t.append([1])
    for j in range(0,i):
         t[i+1].append(t[i][j]+t[i][j+1])
    t[i+1].append(1)
