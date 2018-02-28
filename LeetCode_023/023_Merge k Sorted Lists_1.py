#!usr/bin/env python
#_*_ coding:utf-8 _*_

import os

class ListNode():
    def __init__(self, x)
        self.val = x
        self.next = None

    
class Solution():
    def mergeKLists(self, lists):
        self.Node = []
        head = cur = ListNode(0)
        
        for l in lists:
            while(l):
                self.Node.append(l.val)
                l = l.next
        a = sorted(self.Node)
        for x in a:
            cur.next = ListNode(x)
            cur = cur.next

        return head.next
