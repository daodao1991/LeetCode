#!usr/bin/env python
#_*_ coding:utf-8 _*_

import os

class Solution():
    def removeDuplicates(self, array):
        count = 0
        for i in range(len(array)):
            if(i>0 and array[i]==array[i-1]):
                continue
            count+=1

        return count



list1 = input("请输入n个整数：").split()
a = [int(x) for x in list1]
res = Solution()
new_length = res.removeDuplicates(a)
print(new_length)

os.system('pause')
