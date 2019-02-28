#!/usr/bin/env python3
# -*- coding:utf-8 -*-

"""
思路：该题可以理解为斐波那契数列的应用，假设青蛙跳上n级台阶，则分为两种情况:一是先跳到了
      n-1级台阶，然后跳1级跳到n级，二是先跳到了n-2级台阶，然后跳2级跳到了n级。所以，问题
      可以递归地变为f(n) = f(n-1) + f(n-2)
"""

class Solution:
    def jumpFloor(self, number):
        if number <= 0:
            return -1
        elif number == 1:
            return 1
        elif number == 2:
            return 2
        else:
            s = [1,2]
            for i in range(2,number):
                new = s[i-1] + s[i-2]
                s.append(new)
            return s[number-1]
