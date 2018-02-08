#_*_ coding:utf-8 _*_

import os

def intTORoman(num):
    strs = ['M','CM','D','CD','C','XC','L','XL','X','IX','V','IV','I']
    nums = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]

    res = ""

    for (i,j) in enumerate(nums):
        while(num >= j):
            res += strs[i]
            num -= j
        if(num == 0):
            return res

def main():
    a_str = input("请输入一个1到3999之间的整数：")
    a = int(a_str)
    print(intTORoman(a))
    os.system('pause')

main()
