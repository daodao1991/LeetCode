#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res;
		vector<int> Nofound = { -1,-1 };
		vector<int>::iterator it;
		int position, numCount, i = 1;
		//利用find()函数查找目标值是否存在，返回指向第一个目标值的迭代器
		it = find(nums.begin(), nums.end(), target);
		//利用distance()函数计算出第一个目标值的位序
		position = distance(nums.begin(),it);
		if (it != nums.end()) {
			res.push_back(position);
			//利用count()函数计算目标值出现的次数，若超过一次，则将首尾元素的位序放入res
			numCount = count(nums.begin(), nums.end(), target);
			if (numCount <= 1) { 
				res.push_back(position);
			}
			else {
				res.push_back(position + numCount - 1);
			}
			return  res;
		}
		else {
			return	Nofound;
		}

	}
};

int main() 
{
	vector<int> nums = { 5,7,7,8,8,10 };
	vector<int> output;
	int target = 10;
	Solution Obj;
	output = Obj.searchRange(nums, target);
	int L = output.size();
	int count = L - 1;

	cout << "[";
	for (int i = 0; i < L; i++) {
		cout << output[i];
		if (count > 0) {
			cout << ",";
			count -= 1;
		}
	}
	cout << "]" << endl;

	system("pause");
	return 0;
}