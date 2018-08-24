#!usr/bin/env python
#-*- coding:utf-8 -*-


#使用二分查找(binary search)的思想
class Solution(object):
    def search(self, nums, target):
        lo,hi = 0,len(nums)-1
        while(lo < hi):
            mid = (lo+hi) // 2
            if nums[mid] == target:
                return mid
            if nums[0] <= target < nums[mid] or target < nums[mid] < nums[0] or \
               nums[mid] < nums[0] <= target:
                hi = mid - 1
            else:
                low = mid + 1

        return -1
