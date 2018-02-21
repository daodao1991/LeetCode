# _*_ coding:utf-8 _*_

import os

def fourSum(nums, value):
    res = []
    nums.sort()

    for i in range(len(nums)-3):
        for j in range(i+1,len(nums)-2):
            m = j+1
            n = len(nums)-1

            while(m < n):
                if(nums[i] + nums[j] + nums[m] + nums[n] == value):
                    res.append([nums[i],nums[j],nums[m],nums[n]])
                    m+=1
                    n-=1
                elif(nums[i] + nums[j] + nums[m] + nums[n] < value):
                    m+=1
                else:
                    n-=1
    return res


a = input("请输入一个整数列表：").split()
b = [int(x) for x in a]
val = int(input("请输入一个目标值："))
result = fourSum(b, val)
print(result)

os.system('pause')
