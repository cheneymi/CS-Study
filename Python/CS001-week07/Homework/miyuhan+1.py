def common(x,y):
    for i in range(len(x)):
        for j in range(len(y)):
            if x[i]==y[j]:
                return True
    return False

print(common([1,2,3,4,5],[6,7,8,9]))
print(common([10,9,8,7,6],[6,5,4,3]))
