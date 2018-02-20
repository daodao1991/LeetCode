# _*_ coding:utf-8 _*_

import os

def LetterCombinations(string):
    res = []
    
    str1 = list(string)
    list1 = [int(x) for x in str1]
    print(list1)
    d = dict(zip((2,3,4,5,6,7,8,9),('abc','def','ghi','jkl','mno','pqrs','tuv','wxyz')))
    list2 = []
    for i in range(len(list1)):
        list2.append(list(d[list1[i]]))
    for j in range(len(list2)-1):
        for k in range(j+1, len(list2)):
            list3 = list2[j]
            list4 = list2[k]
            for m in range(len(list3)):
                for n in range(len(list4)):
                    a = list3[m]
                    b = list4[n]
                    res.append(a+b)
    return res


str1 = input("请输入一个手机键盘上的数字组合：")
result = LetterCombinations(str1)
print(result)

os.system('pause')
