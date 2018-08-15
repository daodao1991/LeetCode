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

		/*ͨ��������֪���������е�Ԫ�������ֵΪ���Ϊ�����֣�
		�������ֵ�λ�����ǲ�ͬ��*/

		//����ͨ������max_element()�ҵ������е����ֵ��λ��,�䷵�ص��ǵ�����
		auto max = max_element(nums.begin(), nums.end());
		distanceMax = distance(nums.begin(), max); //distance()��������������֮��ľ���

		it = find(nums.begin(), nums.end(), target);//��������ǰĿ��ֵ�������е�λ��		
		if (it != nums.end()) {
			//������copy�����������򣬴�С����
			sort(copy.begin(), copy.end());
			it1 = find(copy.begin(), copy.end(), target);
			pos = distance(copy.begin(), it1);

			if (it <= max) {  //�����ֵǰ��Ԫ�ص�λ��
				index = pos- (L - (distanceMax+1)); //ע��˴�distanceMaxΪ����
			}
			else {  //�����ֵ���Ԫ�ص�λ��
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

	cout << "������һ��Ŀ��ֵvalue��" << endl;
	cin >> value;
	index = Obj.search(vec, value);
	cout << index << endl;
	
	system("pause");
	return 0;
}