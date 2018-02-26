#!usr/bin/env python
#_*_ coding:utf-8 _*_

import os

class ListNode():
    """定义结点类"""
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution():
    def mergeTwoLists(self, l1, l2):
        result = cur = ListNode(0)

        while(l1 and l2):
            if(l1.val < l2.val):
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next

        #当一个链表放完后，直接把另一个链表剩余的部分放进去就好了
        cur.next = l1 or l2

        return result.next


array1 = [1,2,4,5]
array2 = [3,3,4,6]
l1 = ListNode(array1[0])
p1 = l1
l2 = ListNode(array2[0])
p2 = l2

for i in array1[1:]:
    p1.next = ListNode(i)
    p1 = p1.next

for j in array2[1:]:
    p2.next = ListNode(j)
    p2 = p2.next

s = Solution()
res = s.mergeTwoLists(l1, l2)

while(res.next):
    print(str(res.val)+'->',end = '')
    res = res.next
print(res.val)

os.system('pause')
