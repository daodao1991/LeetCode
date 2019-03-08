#!/usr/bin/env python
# -*- coding:utf-8 -*-

class Solution:
    def multiply(self, num1, num2):
        res = 0
        for i, a in enumerate(num1[::-1]):
            # 翻转是为了方便计算对应数字的次方数
            tmp1 = int(a)*(10**i)
            for j, b in enumerate(num2[::-1]):
                tmp2 = int(b)*(10**j)
                res += tmp1 * tmp2
        return str(res)
