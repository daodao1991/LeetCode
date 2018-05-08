#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() <= 1)	return;
		bool is_haveNextPer = false;
		
		/*使用了两个反向迭代器*/
		vector<int>::reverse_iterator  p1 = nums.rbegin(), p2 = nums.rbegin();
		for (int i = 1; i < nums.size(); ++i)
		{
			++p1;
			while (p1 - p2 > 0)
			{
				if (*p1 < *p2)
				{
					iter_swap(p1, p2); 
					is_haveNextPer = true;
					break;
				}
				else
				{
					++p2;
				}
			}

			if (is_haveNextPer)  break;
			p2 = nums.rbegin();
		}


		if (is_haveNextPer)
		{
			--p1;
			p2 = nums.rbegin();
			while (p1 - p2 > 0)
			{
				iter_swap(p2, p1);
				++p2;
				--p1;
			}
		}
		else
		{
			sort(nums.begin(), nums.end());
		}
	}
};