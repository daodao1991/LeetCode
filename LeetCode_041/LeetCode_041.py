#!/usr/bin/env python
#-*- coding:utf-8 -*-

class Solution:
    def firstMissingPositive(self, nums):
        if len(nums) == 0:
            return 1
        nums.sort()
        i = 0
        while(i<len(nums) and nums[i] <= 0):
            i += 1
        if i == len(nums):
            return 1
        else:
            nums_pos = nums[i:]
        j = 0
        while j<len(nums_pos):
            if nums_pos[0] > 1:
                return 1
            if j>0 and nums_pos[j]-nums_pos[j-1] > 1:
                return nums_pos[j-1] + 1
            while j< len(nums_pos)-1 and nums_pos[j] == nums_pos[j+1]:
                j += 1
            j += 1
        return nums_pos[j-1] + 1


obj = Solution()
a = input("请输入几个整数：").split()
nums = [int(i) for i in a]
a = obj.firstMissingPositive(nums)
print(a)
