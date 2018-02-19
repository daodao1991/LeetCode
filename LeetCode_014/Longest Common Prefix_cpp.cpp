#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>

using namespace std;


class Solution {
public:
	string LongestCommonPrefix(vector<string> &strings)
	{
		if (strings.empty())   return "";

		/*纵向扫描，从位置0开始，对每一个位置比较所有的字符串*/
		for (int index = 0; index < strings[0].size(); ++index)
		{
			for (int i = 1; i < strings.size(); ++i)
			{
				if (strings[i][index] != strings[0][index])
				{
					return strings[0].substr(0, index);
				}
			}
		}

		return strings[0];
	}
};



int main()
{
	string a, res;
	vector<string> str1;
	Solution Obj;

	cout << "请输入多个字符串:" << endl;
	while (cin >> a)
	{
		str1.push_back(a);
	}

	res = Obj.LongestCommonPrefix(str1);
	cout << res << endl;

	system("pause");
	return 0;
}