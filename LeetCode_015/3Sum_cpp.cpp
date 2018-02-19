#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>  //ע��Ҫ������ͷ�ļ�

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int> &nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());   //�ȶ����������������

		for (int i = 0; i != nums.size(); ++i)
		{ 
			if (i > 0 && nums[i] == nums[i - 1])  continue;

			int values = -nums[i];
			int j = i + 1, k = nums.size() - 1;			
			while (j < k)
			{
				if (nums[j] + nums[k] == values)
				{
					res.push_back({ nums[i],nums[j],nums[k] });
					while (j < k && nums[j] == nums[j + 1])  ++j;
					while (j < k && nums[k] == nums[k - 1])  --k;

					++j;
					--k;
				}
				else if (nums[j] + nums[k] < values)
				{
					++j;
				}
				else
				{
					--k;
				}

			}


		}

		return res;
	}
};


int main()
{
	int a;
	vector<int> numbers;
	vector<vector<int>> result;
	vector<int> middle;
	//vector<vector<int>>::iterator IT = result.begin();
	Solution Obj;

	cout << "������һ���������飺" << endl;
	while (cin >> a)
	{
		numbers.push_back(a);
	}

	result = Obj.threeSum(numbers);

	for (int index = 0; index < result.size(); ++index)
	{
		middle = result[index];
		for (vector<int>::iterator it = middle.begin(); it != middle.end(); ++it)
		{
			cout << *it << ' ';
		}

		cout << endl;
	}

	system("pause");
	return 0;
}