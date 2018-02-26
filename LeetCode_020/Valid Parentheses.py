#!/usr/bin/env python
#_*_ coding:utf-8 _*_

import os

class Solution:

    def isValid(self, s):
        """判断是否为有效的括号匹配"""
        stack = []
        for i in s:
            if(i=='(' or i=='[' or i=='{'):
                stack.append(i)
            elif not stack:
                return False
            elif(i==')' and stack.pop()!='('):
                return False
            elif(i==']' and stack.pop()!='['):
                return False
            elif(i=='}' and stack.pop()!='{'):
                return False
        return not stack


str1 = input("请输入一个只包含括号的字符串：")
Obj = Solution()
print(True if Obj.isValid(str1) else False)
