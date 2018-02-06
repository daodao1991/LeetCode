#include<iostream>
#include<vector>
#include<algorithm> //容器vector成员函数头文件，否则无法使用max_element
#include<stdlib.h>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		vector<int>::size_type left = 1;
		vector<int>::size_type right = height.size();

		int h = 0, area = 0;
		vector<int> Area;

		while (left != right)
		{
			h = (height[left - 1] <= height[right - 1] ? height[left - 1] : height[right - 1]);
			area = (right - left)*h;
			Area.push_back(area);

			if (height[left - 1] <= height[right - 1])
			{
				left++;
			}
			else
			{
				right--;
			}
		}

		vector<int>::iterator max = max_element(begin(Area), end(Area));
		return *max;
	}
};


int main()
{
	Solution Obj;
	int a, MAX_AREA;
	vector<int> num;
	cout << "请输入n个非负整数：" << endl;

	while (cin >> a)
	{
		num.push_back(a);
	}

	MAX_AREA = Obj.maxArea(num);
	cout << "求出这n个数所组成矩形面积的最大值为：" << MAX_AREA << endl;

	system("pause");
	return 0;
}
