#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		vector<int> copy(nums);
		vector<int>::iterator it;
		int L = nums.size;
		int pos;

		sort(copy.begin(), copy.end());
		it = copy.find(copy.begin(), copy.end(), target);
		if (it != copy.end()) {
			pos = distance(copy.begin(), it);
		}

		return pos - nums[0];
	}
};