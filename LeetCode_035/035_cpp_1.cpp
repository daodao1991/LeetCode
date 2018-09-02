#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int l = 0, r = nums.size();
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] < target) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}

		return l; 
		//此时的l即为目标值的位置，或者是目标值要插入的位置
		//！！！这个函数写得很吊！！！
	}
};