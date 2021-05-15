#include <iostream>
#include <vector>


/***** 解题思路 *****
 * 
 *     1 -> 2 -> 3 -> 4 -> 5
 *           >>>>>
 *     5 -> 4 -> 3 -> 2 -> 1
 * 
 */

using namespace std;

// 定义链表中的结点结构 
typedef int ElemType;
typedef struct ListNode {
    ElemType val;
    struct ListNode *next;
}ListNode, *LinkList;



class Solution {
public:
    ListNode* ReverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        // head为当前结点，pre/next分别为直接前驱结点和直接后继结点
        ListNode* pre = nullptr;
        ListNode* next = nullptr;

        while(head != nullptr) {
            // 先将后继结点保存下来，为后边的结点移动做准备
            next = head->next;
            // 然后将当前结点的指针域指向前驱结点，实现当前结点的反转
            head->next = pre;
            // 然后结点后移
            pre = head;
            head = next;
        } // head不断地被置为下一个结点，当head为空时说明已经反转完毕了，循环终止

        return pre;
    }

};