#! /usr/bin/env python
#-*- coding:utf-8 -*-

'''
    采用深度优先搜寻(DFS)的思想,而DFS的实现要采用递归的方式，
    python默认的递归深度很有限,大概是900多的样子，当递归深度
    超过这个值的时候，就会引发这样的一个异常。
    解决的方式是手工设置递归调用深度，方式为
'''    

import sys
sys.setrecursionlimit(1000000)


class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]]
        :type target: int
        :rtype: List[List[int]]]]
        """
        res = []
        temp = []
        candidates.sort()
        self.combinationSumDFS(candidates, target, 0, temp, res)
        return res


    def combinationSumDFS(self, candidates, target, start, temp, res):
        if target < 0:
            return
        elif target == 0:
            print(temp)
            res.append(temp)
            #print(res)
        else:
            for i in range(start, len(candidates)):
                temp.append(candidates[i])
                self.combinationSumDFS(candidates, target-candidates[i], i, temp, res)
                temp.pop()
        print(['##'] + res)

obj = Solution()
nums = [2, 3, 6, 7]
res = obj.combinationSum(nums, 7)
print(res)
