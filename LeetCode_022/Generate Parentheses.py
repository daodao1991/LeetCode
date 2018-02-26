#!usr/bin/env python
#_*_ coding:utf-8 _*_

import os

class Solution():
    def generateParenthesis(self, n):
        self.res = []
        self.generate(n, n, '')

        return self.res
    

    def generate(self, left, right, str1):
        if(left==0 and right==0):
            self.res.append(str1)
        
        if(left > 0):
            self.generate(left-1, right, str1+'(')

        if(right > 0 and right > left):
            self.generate(left, right-1, str1+')')



result = Solution()
num = int(input("请输入一个整数："))
a = result.generateParenthesis(num)
print(a)

os.system('pause')
