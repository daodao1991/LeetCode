#!usr/bin/env python
#-*- coding:utf-8 -*-

import os

class Solution():
    def removeElement(self, nums, val):
        j = 0
        for i in range(len(nums)):
            if(nums[i] != val):
                nums[j] = nums[i]
                j+=1
        return j


a = input("请为数组输入一组整数：\n").split()
nums = [int(x) for x in a]
print(nums)
val = int(input("输入一个目标值："))

Obj = Solution()
length = Obj.removeElement(nums, val)
print(nums)
print(length)


