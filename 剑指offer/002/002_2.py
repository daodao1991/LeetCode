#!/usr/bin/env python
#-*- coding:utf-8 -*-


#使用正则表达式
import re
class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        pat = ' '
        new_s = re.sub(pat, '%20', s)
        return new_s
