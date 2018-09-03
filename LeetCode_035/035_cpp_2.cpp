#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

class Solution {
public:
	//采用递归的形式
	int searchInsert(vector<int>& nums, int target) {

	}

	int search(vector<int>& nums, int l, int r, int target) {
		int l = 0, r = nums.size() - 1;
		if (l < r) {
			return l;  /*此步是关键所在！！！ 当target不在nums中时，此处便是递归结束的条件,返回的值就是
					   nums中大于或等于target的那个数所在的位置，即target应该插入的位置*/
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