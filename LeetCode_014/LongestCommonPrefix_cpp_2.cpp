#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>

using namespace std;
class Solution {
public:
	string LongestCommonPrefix(vector<string> &str) {

		string prefix = str[0];

		/*用当前的最长公共前缀prefix，依次与字符串数组中的字符串比较*/
		for (int i = 1; i != str.size(); ++i)
		{
			if (prefix.length() == 0 || str[i].length() == 0)  return "";

			/*取两两比较的字符串的最短长度*/
			int len = prefix.length() < str[i].length() ? prefix.length() : str[i].length();

			for (int j = 0; j < len; ++j)
			{
				if (prefix[j] != str[i][j])
				{
					prefix = prefix.substr(0, j);
					break;
				}
			}
			
		}

		return prefix;
	}
};

int main()
{
	string a, res;
	vector<string> str1;
	Solution Obj;

	cout << "请输入n个字符串：" << endl;

	while (cin >> a)
	{
		str1.push_back(a);
	}

	res = Obj.LongestCommonPrefix(str1);
	cout << res << endl;

	system("pause");
	return 0;
}