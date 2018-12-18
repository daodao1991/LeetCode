#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

class Solution {
public:
	vector<int> res_vector;
	vector<int> printListFromTailToHead(ListNode* head) {
		if(head == NULL){
			return res_vector;
		}
		if(head->next != NULL){
			res_vector = printListFromTailToHead(head->next);
		}
		res_vector.push_back(head->val);
		return res_vector;
};
