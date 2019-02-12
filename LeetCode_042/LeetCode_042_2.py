#!/usr/bin/env python3
# -*- coding:UTF-8 -*-

"""
思路：
    对于数组中的每个元素，我们可以找到雨后它能捕获的最大水位，它等于两边的条的最大高度减去它自己的高度中的最小值。
"""

class Solution:
    def trap(self, height):
        res = 0
        Len = len(height)
        for i in range(1, Len - 1):
            max_left = 0
            max_right = 0
            # 从当前位置开始，寻找列表左半部分高度的最大值
            for j in range(i, -1, -1):
                max_left = max(max_left, height[j])
            # 从当前位置开始，寻找列表右半部分高度的最大值
            for j in range(i, Len):
                max_right = max(max_right, height[j])
                
            res += min(max_left, max_right) - height[i]
        return res
