#include <iostream>
#include <vector>
#include <stack>

/***** 解题思路 *****
 * 
 *     从尾到头打印链表，想到对链表进行遍历，然后使用堆栈的LIFO存放链表中的元素，再依次出栈
 * 
 */


using namespace std;

typedef int ElemType;
typedef struct LNode {
    ElemType val;
    struct LNode *next;
}LNode, *LinkList;


class Solution {
public: 
    vector<int> printListFromTailToHead(LinkList head) {
        // head为头指针，其存放的是链表中第一个结点的位置
        vector<int> res;
        if (head == nullptr) {
            return res;
        }

        stack<int> S;
        LNode *p = head;

        while (p != nullptr) {
            S.push(p->val);
            p = p->next;
        }
        // 注意！！遍历stack是不断地去判断栈是否为空，不是用for循环
        while(!S.empty()) {
            res.push_back(S.top());
            S.pop();
        }

        return res;
    }

};