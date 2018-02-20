# _*_ coding:utf-8 _*_

import os

def threeSum(nums):
    res = []
    nums.sort()
    
    for i in range(len(nums)):
        if(nums[i]>0): break
        if(i>0 and nums[i]==nums[i-1]): continue
        
        value = -nums[i]
        m = i+1
        n = len(nums)-1
        while(m < n):
            if(nums[m] + nums[n] == value):
                res.append([nums[i],nums[m],nums[n]])
                m+=1
                n-=1
            elif(nums[m] + nums[n] < value):
                m+=1
            else:
                n-=1

    return res

a = input("请输入一个整数列表：").split()
b = [int(x) for x in a]
result = threeSum(b)
print(result)

os.system('pause')
