#!usr/bin/env python
#_*_ coding:utf-8 _*_


'''
class ListNode():
    def __init__(self, x):
        self.val = x
        self.next = None
'''
class Solution():
    def swapPairs(self, head):
        firstHead = ListNode(0)
        firstHead.next = head

        pre, cur = (firstHead, head)
        while(cur and cur.next):
            pre.next = cur.next
            cur.next = pre.next.next
            pre.next.next = cur

            pre, cur = cur, cur.next
            
        return firstHead.next
        
