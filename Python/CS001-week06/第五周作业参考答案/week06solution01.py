def second(x):
    #请输入你的代码
    x.remove(max(x))
    return max(x)

print(second([1,2,3,4,5]))
print(second([10,9,8,7,6]))
