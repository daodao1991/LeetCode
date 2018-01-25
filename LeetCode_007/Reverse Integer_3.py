#_*_ coding:utf-8 _*_

##import os
def reverse(x,*arg):
    flag = 1 if x >= 0 else -1
    a = abs(x)
    new_x = flag * int(str(a)[::-1])
    return new_x if new_x >= -9223372036854775808 and new_x <= 9223372036854775807 else 0

a = (input("请输入一个整数："))
print(reverse(a))
#os.system('pause')
