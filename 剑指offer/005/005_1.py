#!/usr/bin/env python
#-*- coding:utf-8 -*-

'''
用列表实现栈的结构,整体思路不变
'''
class Solution:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def push(self, node):
        self.stack1.append(node)

    def pop(self):
        if(self.stack2 == []):  #若栈2为空
            while(self.stack1):  #只要栈1不为空
                self.stack2.append(self.stack1.pop())
        return self.stack2.pop()
