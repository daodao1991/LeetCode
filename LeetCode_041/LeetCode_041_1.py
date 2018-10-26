#!/usr/bin/env python
#-*- coding:utf-8 -*-
'''
这种思路主要的逻辑是，for any array whose length is l, the first missing positive 
must be in range [1,...,l+1], so we only have to care about those elements in this 
range and remove the restrest.
'''


class Solution:
    def firstMissingPositive(self, nums):
        nums.append(0)  #加上0，是为了保证l+1在考虑范围内
        n = len(nums)
        for i in range(len(nums)): #delete those useless elements
            if nums[i]<0 or nums[i]>=n:
                nums[i]=0

        #use the index as the hash to record the frequency of each number
        #此时数组中的元素都在[0,n) 这一步是神人的操作，我完全想不到……
        for i in range(len(nums)): 
            nums[nums[i]%n] += n
        #此时的情况应该是，前面几位都是大于0的数，只要大于0，说明该下标对应的数出现过
        #直到出现0，则该位置下标即为要寻找的那个缺失的最小的正整数
        for i in range(1,len(nums)):
            if nums[i]/n==0:
                return i
        return n

obj = Solution()
a = input("请输入几个整数：").split()
nums = [int(i) for i in a]
a = obj.firstMissingPositive(nums)
print(a)
