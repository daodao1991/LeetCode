#!/usr/bin/env python
#-*- coding:utf-8 -*-

class Solution():
        def combinationSum2(self, candidates, target):
                res = []
                temp = []
                candidates.sort()
                self.DFS(candidates, target, 0, temp, res)
                return res
            

        def DFS(self, nums, target, idx, temp, res):
            if target < 0:
                return
            elif target == 0:
                res.append(list(temp))
            else:
                for i in range(idx, len(nums)):
                    if(i > idx and nums[i] == nums[i-1]):
                        continue
                    else:
                        temp.append(nums[i])
                        self.DFS(nums, target-nums[i], i+1, temp, res)
                        temp.pop()

obj = Solution()
nums = [10, 1, 2, 7, 6, 1, 5]
res = obj.combinationSum2(nums, 8)
print(res)
