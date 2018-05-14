#!usr/bin/env python
#-*- coding:utf-8 -*-


class Solution:
    def nextPermutation(self, nums):
        flag = False
        p1 = len(nums) - 2

        while(p1 >= 0):
            p2 = len(nums) -1
            while(p1 - p2 < 0 and nums[p1] >= nums[p2]):
                p2 -= 1
            if(p1 >= p2):
                p1 -= 1
            else:
                nums[p1], nums[p1+1:], flag = nums[p2], sorted(nums[p1+1:p2], nums[p1], nums[p2+1:]), True

        if not flag:
            nums.sort()
