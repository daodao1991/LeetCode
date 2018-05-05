#!usr/bin/env python 
#_*_ coding:utf-8 _*_

class Solution:
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        res = []
        if(len(words) == 0):
            return []
        
        dict1 = dict.fromkeys(words, 0)
        #用字典1存放列表words中的元素和其对应的出现次数
        for a in words:
            num = words.count(a)
            dict1[a] = num
        
        l = len(s)
        m = len(words)
        n = len(words[0])
        
        
        for i in range(l - m * n +1):
            dict2 = dict.fromkeys(words, 0)
            #用字典2存放枚举过程中words中的元素出现的次数
            for j in range(m):
                substr = s[(i+j*n):(i+j*n+n)]
                if(substr in dict1.keys()):
                    dict2[substr] += 1
                    if(dict2[substr] > dict1[substr]):
                        j -= 1
                        #注意不要忘了减1，否则有可能
                        #最后一个substr不满足要求，但下边
                        #if(j == m-1)仍然满足的情况
                        break
                else:
                    j -= 1
                    break
                    
            if(j == m-1):
                res.append(i)
                
        return res



s = "abclmnOPQabcXYZabclmnRST"
words = ['abc','lmn','XYZ']
Obj = Solution()
a = Obj.findSubstring(s, words)
print(a)
