#!/usr/bin/env python
#-*- coding:utf-8 -*-


class Solution:
    # array 二维列表
    def Find(self, target, array):
        Row = len(array)
        Col = len(array[0])
        #初始化放在最后一行,即从二维数组的左下角开始遍历
        i = Row - 1
        j = 0
        while(i >= 0 and j < Col):
            if array[i][j] == target:
                return True
            elif array[i][j] < target:
                j += 1
            else:
                i -=1
        return False
