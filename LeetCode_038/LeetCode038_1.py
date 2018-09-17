#!/usr/bin/env python
#-*- coding:utf-8 -*-

"""
解题思路:
    首先,将letter置为第一个字符，然后查看letter是否连续，
当循环到出现一个与之前的字符(存在letter中)不同的字符时，随后将
记录之前字符出现次数的count和letter添加到下一个字符串上temp，
同时将letter重新置位新的字符，剩下的同理,共循环n-1次，因为开头
将s置位了'1'
"""

class Solution:
    def countAndSay(self, n):
        s = '1'
        for _ in range(n-1):
            letter, temp, count = s[0], '', 0
            for char in s:
                if letter == char:
                    count += 1       #第一个字符肯定会加1
                
                else:               
                #当遇到一个新字符时，把之前的count和字符加到temp上
                    temp += str(count) + letter
                    letter = char
                    count = 1
            temp += str(count) + letter
            s = temp
        return s
            
