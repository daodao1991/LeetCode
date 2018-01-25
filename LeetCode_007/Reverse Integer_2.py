#_*_ coding:utf-8 _*_

import os

def reverse(x, *self):
    a = abs(x)
    a_list = list(str(a))      #字符串转化为列表
    a_list.reverse()
    str_new = ''.join(a_list)  #列表转化为字符串
    new_x = int(str_new)
    new_x = new_x if x>=0 else -new_x
    return new_x if new_x >= -9223372036854775808 and new_x <= 9223372036854775807 else 0


a = int(input("请输入一个整数："))  #每次都忘了input()返回的是字符串型
print(reverse(a))
os.system('pause')
