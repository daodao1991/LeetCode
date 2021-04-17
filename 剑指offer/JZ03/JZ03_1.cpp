#include <iostream>
#include <vector>
#include <algorithm>

/***** 解题思路 *****
 * 
 *     顺序遍历链表将元素依次添加到数组中后，再对数组进行翻转。
 * 
 */


using namespace std;

// 定义单链表的结点结构
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
        LNode *p = head;  //即p指向第一个结点

        while(p != nullptr) { // 只要当前p所指的结点不为空，说明后边还有结点
            res.push_back(p->val);
            p = p->next;
        }
        
        //翻转可以使用STL自带函数reverse(),也可以自己实现
        // reverse(res.begin(), res.end());

        int i = 0, j = res.size()-1, tmp;
        while (i < j) {
            tmp = res[i];
            res[i] = res[j];
            res[j] = tmp;

            i++;
            j--;
        }

        return res;
    }
};