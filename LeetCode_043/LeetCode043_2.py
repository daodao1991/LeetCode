#!/usr/bin/env python
# -*- coding:utf-8 -*-

class Solution:
    def multiply(self, num1:str, num2:str) -> str:
        res = [0]*(len(num1)+len(num2))
        for i in range(len(num1)-1, -1, -1):
            carry = 0
            for j in range(len(num2)-1, -1, -1):
                # 计算对应位置相乘的结果，再加上进位
                tmp = int(num1[i]) * int(num2[j]) + carry
                # 计算当前位置是否有进位
                carry = (res[i+j+1] + tmp) // 10
                # 更新当前位置
                res[i+j+1] =  (res[i+j+1] + tmp) % 10
            # 里边循环的最后一次计算的时res[i+1],要考虑是否有进位
            res[i] += carry
