#!/usr/bin/env python
#-*- coding:utf-8 -*-

class Solution:
    ##记录每个字符串的第一个字符，和后边出现的连续字符串的情况
    ##循环n-1次，因为设定字符串初始值为"1"
    def countAndSay(self, n):
            s = '1'
            for _ in range(n-1):
                let, temp, count = s[0], '', 0
                for l in s:
                    if let == l:
                        count += 1
                    else:
                        temp += str(count)+let
                        let = l
                        count = 1
                temp += str(count)+let
                s = temp
            return s
