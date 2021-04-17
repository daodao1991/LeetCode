#include <iostream>
#include <vector>


/***** 解题思路 *****
 * 
 *     由于是从尾到头打印链表元素，故可以考虑遍历链表时采用递归的思路 
 * 
 */


using namespace std;

// 先定义链表中的结点结构 
typedef int ElemType;
typedef struct LNode {
    ElemType val;         // 值域
    struct LNode *next;   // 链域
}LNode, *LinkList;


class Solution {
public:
    vector<int> res;
    vector<int> printListFromTailToHead(LinkList head) {
        if (head == nullptr) {
            return res;
        }

        LNode *p = head;
        if(p != nullptr) {
            // 注意！！ 因为要从后往前将链表中的元素添加进数组中，所以应将添加操作放在递归函数的后边
            if (p->next != nullptr) {
                printListFromTailToHead(p->next); // 将下一个结点作为头结点递归地传入函数中
            }
            res.push_back(p->val);
        }

        return res;
    }

};