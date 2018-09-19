#!/usr/bin/env  python
#-*- coding:utf-8 -*-

class Solution():
    def countAndSay(self, n):
        if n == 1:
            return '1'
        s = self.countAndSay(n-1)

        pre, count, temp = s[0], 1, ''
        for i in range(1, len(s)):
            if s[i] == pre:
                count += 1
            else:
                temp += str(count) + pre
                pre = s[i]
                count = 1
        temp += str(count) + pre
        s = temp
        return s
