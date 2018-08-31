#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int idx1 = lower_bound(nums, target);
		int idx2 = lower_bound(nums, target + 1) - 1;
		if (idx1 < nums.size() && nums[idx1] == target)
			return{ idx1, idx2 };
		else
			return{ -1, -1 };
	}
	//二分查找的前提是序列已经是有序排列的！！！
	//C++参考手册中有lower_bound()这个函数，这里相当于自己写了一个lower_bound(),写得很好！！
	//返回的是一个非递减序列中第一个大于等于值target的位置
	int lower_bound(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int mid = (r - l) / 2 + l;
			if (nums[mid] < target)
				l = mid + 1;
			else
				r = mid - 1;
		}
		return l;
	}
};