#!usr/bin/env python
#_*_ coding:utf-8 _*_

import os
import queue

'''
class ListNode():
    def __init__(self, x):
        self.val = x
        self.next = None
'''
class Solution():
    def mergeKLists(self, lists):
        que = queue.PriorityQueue()
        head = cur = ListNode(0)

        for n in lists:
            que.put((n.val, n))
    
        while not que.empty():
            #优先队列默认的是用小根堆实现，即队头元素最小
            node = que.get()[1]
            cur.next = node
            cur = cur.next

            node_next = node.next
            if(node_next):
                que.put((node_next.val, node_next))
                
        return head.next
        
