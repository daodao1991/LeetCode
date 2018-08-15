#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		vector<int> copy(nums);
		vector<int>::iterator it, it1;
		int L = nums.size();
		int distanceMax, pos, index;

		/*通过分析可知，将容器中的元素以最大值为界分为两部分，
		这两部分的位序求法是不同的*/

		//首先通过函数max_element()找到容器中的最大值的位序,其返回的是迭代器
		auto max = max_element(nums.begin(), nums.end());
		distanceMax = distance(nums.begin(), max); //distance()返回两个迭代器之间的距离

		it = find(nums.begin(), nums.end(), target);//重新排序前目标值在容器中的位序		
		if (it != nums.end()) {
			//对容器copy进行重新排序，从小到大
			sort(copy.begin(), copy.end());
			it1 = find(copy.begin(), copy.end(), target);
			pos = distance(copy.begin(), it1);

			if (it <= max) {  //求最大值前的元素的位序
				index = pos- (L - (distanceMax+1)); //注意此处distanceMax为距离
			}
			else {  //求最大值后的元素的位序
				index = pos + (distanceMax+1);
			}
			return index;
		}		
		else {
			return -1;
		}
	}
};

int main()
{
	Solution Obj;
	vector<int> vec = { 5,7,13,25,0,1,3 };
	int index, value;

	cout << "请输入一个目标值value：" << endl;
	cin >> value;
	index = Obj.search(vec, value);
	cout << index << endl;
	
	system("pause");
	return 0;
}