#include <iostream>
#include <vector>


/***** 解题思路 *****
 * 
 *     采用递归的思路，先通过递归走到链表的末端结点，然后每层递归函数实现后边一个结点指向当前结点的反转
 */

using namespace std;

typedef int ElemType;
typedef struct ListNode {
    ElemType val;
    struct ListNode *next;
}ListNode, *LinkList;


class Solution {
public:
    ListNode* newReverseHead;
    ListNode* ReverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* p = head;
        if (p->next != nullptr) {
            newReverseHead = ReverseList(p->next);
        }

        p->next->next = p;
        p->next = nullptr;

        return newReverseHead;
    }

};