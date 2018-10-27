#!usr/bin/env python3
#-*- coding:utf-8 -*-

import sys
sys.setrecursionlimit(1000000)

class Solution:
    def myPow(self, x, n):
        #递归终止的边界条件
        if n == 0:
            return 1     
        # n分为奇数偶数
        m = int(n/2)
        half = self.myPow(x, m)
        if n%2 == 0:  
            res = half*half
            return res
        elif n > 0:           #奇数的情况又分为正负两种情况
            res = half*half*x
            return res
        else:
            res = half*half*(1/x)  
            return res

obj = Solution()
a = input("输入要求的幂指数的底数和指数：").split()
nums = [float(i) for i in a]
x, a = nums[0], int(nums[1])
print((x,a))
res = obj.myPow(x, a)
print(res)
