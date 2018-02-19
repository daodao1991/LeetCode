#_*_ coding:utf-8 _*_

import os

def RomanToInt(s):
    res = 0
    a = dict([['M',1000],['D',500],['C',100],['L',50],['X',10],['V',5],['I',1]])
    
    for i in range(len(s)):
        if(i == len(s)-1 or a[s[i]] >= a[s[i+1]]):
            res += a[s[i]]
        else:
            res -= a[s[i]]
    return res
str1 = input('请输入一个罗马数字：')
print("其对应的阿拉伯数字为："+str(RomanToInt(str1)))
os.system('pause')
        
    
