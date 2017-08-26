def common(x,y):
    for i in x:
        if i in y:
            return True
    return False

print(common([1,2,3,4,5],[6,7,8,9]))
print(common([10,9,8,7,6],[6,5,4,3]))
