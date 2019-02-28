#!/usr/bin/env python3
# -*- coding:utf-8 -*-

class Solution:
    def trap(self, height):
        res = 0
        Len = len(height)
        l_part = []
        r_part = []
        
        max_left = max_right = 0
        # 从左端到当前位置，寻找最大值
        for ii in range(Len):
            max_left = max(max_left, height[ii])
            l_part.append(max_left)
        # 从右端到当前位置，寻找最大值
        for jj in range(Len-1, -1, -1):
            max_right = max(max_right, height[jj])
            r_part.append(max_right)
        r_part.reverse()

        for i in range(Len):
            res += min(l_part[i], r_part[i]) - height[i]
        return res
