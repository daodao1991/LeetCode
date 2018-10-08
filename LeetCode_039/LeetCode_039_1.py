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
            #res.append(temp)
            '''
            此处，当想把符合条件的temp通过append方法添加到res中时，事实上添加的
            是temp对象的引用，所以当最下边执行temp.pop()时，temp的改变会反应到
            res中，即res也发生了更新。

            所以正确的方法是，把此处的temp转换为一个新的对象，使得此处添加的temp
            和下边的temp不产生关联，即如下：
            '''
            res.append(list(temp))
            #或者res.append(temp+[])
        else:
            for i in range(start, len(candidates)):
                temp.append(candidates[i])
                self.combinationSumDFS(candidates, target-candidates[i], i, temp, res)
                temp.pop()


obj = Solution()
nums = [2, 3, 6, 7]
res = obj.combinationSum(nums, 7)
print(res)
