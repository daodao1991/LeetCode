#_*_ coding:utf-8 _*_

import os

def reverse(x,*arg):
    flag = 1 if x >= 0 else -1
    x = abs(x)
    new_x = 0
    while x:
        new_x = new_x * 10 + x % 10
        x = x//10     ##注意要用地板除
        
    new_x = new_x * flag
    return new_x if new_x <= 9223372036854775807 and new_x >= -9223372036854775808 else 0


a = int(input("请输入一个整数："))
reverse_a = reverse(x = a)
print(reverse_a)
os.system('pause')
