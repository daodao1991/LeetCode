#!/usr/bin/env python3
#-*- coding:utf-8 -*-


class Solution:
    def trap(self, height):
        '''
        :type height: List[int]
        :rtype: int
        '''
        i = 0
        s = 0
        while(i <= len(height)-3):
            if height[i] <= height[i+1]:
                i += 1
            else:
                #得到i之后最近的一个比height[i]大的元素
                l = [ind1 for ind1,x in enumerate(height) if ind1 > i and x >= height[i]]
                if len(l) != 0:
                    s += (l[0] - i - 1) * min(height[i], height[l[0]])
                    for j in range(i+1, l[0]):
                        s -= height[j]
                    i = l[0]
                else:
                    MAX = max(height[i+1:])
                    if height[i+1] == MAX:
                        i += 1
                    else:
                        MAX_1 = max(height[i+1:])
                        m = [ind2 for ind2,y in enumerate(height) if ind2 > i+1 and y == MAX_1]
                        s += (m[0] - i - 1) * height[m[0]]
                        for k in range(i+1, m[0]):
                            s -= height[k]
                        i = m[0]


        return s

obj = Solution()
a = input("请输入几个非负整数：").split()
nums = [int(i) for i in a]
res = obj.trap(nums)
print("所能盛装的水的单位数为：%d" % res)
