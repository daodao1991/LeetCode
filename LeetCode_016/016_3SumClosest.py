# _*_ coding:utf-8 _*_

import os

def threeSumClosest(nums,value):
    res = nums[0] + nums[1] + nums[2]
    diff = abs(res - value)
    nums.sort()
    
    for i in range(len(nums)-2):
        j = i+1
        k = len(nums)-1
        sum = nums[i] + nums[j] + nums[k]
        
        while(j < k):
            new_diff = abs(sum - value)
            if(new_diff < diff):
                diff = new_diff
                res = sum

            if(sum < value):
                j+=1
            else:
                k-=1
    return res



str1 = input("请输入一个整数列表:").split()
list1 = [int(x) for x in str1]
a = int(input("输入一个目标值："))
result = threeSumClosest(list1, a)
print("最接近目标值的和为："+str(result))

os.system('pause')
