#!/usr/bin/env python
#-*- coding:utf-8 -*-


class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        a = s
        str_dict = {' ':'%20'''}
        for key in str_dict:
            a = a.replace(key, str_dict[key])
        return a
