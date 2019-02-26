#!/usr/bin/env python3
# -*- coding:utf-8 -*-

# 采用递归调用的方式会超时，所以用以下形式，本质相同
class Solution:
    def Fibonacci(self, n):
        if n == 0:
            return 0
        elif n == 1:
            return 1
        if n >= 2:
            a = [0,1]
            for i in range(2, n+1):
                a.append(a[i-1] + a[i-2])
        return a[n]
