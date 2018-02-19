#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>

using namespace std;
class Solution {
public:
	string LongestCommonPrefix(vector<string> &str) {

		string prefix = str[0];

		/*�õ�ǰ�������ǰ׺prefix���������ַ��������е��ַ����Ƚ�*/
		for (int i = 1; i != str.size(); ++i)
		{
			if (prefix.length() == 0 || str[i].length() == 0)  return "";

			/*ȡ�����Ƚϵ��ַ�������̳���*/
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

	cout << "������n���ַ�����" << endl;

	while (cin >> a)
	{
		str1.push_back(a);
	}

	res = Obj.LongestCommonPrefix(str1);
	cout << res << endl;

	system("pause");
	return 0;
}