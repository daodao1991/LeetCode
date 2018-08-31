#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int idx = search(nums, 0, nums.size() - 1, target);
		if (idx == -1) {
			return	{ -1,-1 };
		}
		int left = idx, right = idx;
		while (left > 0 && nums[left - 1] == nums[idx]) { --left };
		while (right < nums.size() - 1 && nums[right + 1] == nums[idx]) { ++right };
		return{ left,right };
	}

	//采用递归方式先找到一个值等于target的位置，这个位置是前是后还不确定
	int search(vector<int>& nums, int l, int r, int target) {
		if (l > r) {
			return -1;
		}
		int mid = l + (r - l) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] < target) {
			return search(nums, mid + 1, r, target);
		}
		else {
			return search(nums, l, mid - 1, target);
		}
	}
};