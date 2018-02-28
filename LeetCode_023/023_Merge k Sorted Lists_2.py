#!usr/bin/env python
#_*_ coding:utf-8 _*_

import os

class ListNode():
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution():
    def mergeKLists(self, lists):
        if(len(lists) == 0):
            return None
        n = len(lists)
        while(n > 1):
            k = (n+1)//2
            for i in range(n//2):
                lists[i]  = mergeTwoLists(lists[i], lists[i+k])
            n = k

        return lists[0]


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
