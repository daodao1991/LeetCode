#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		vector<int> longest(s.length());  //默认构造函数每个元素是0
		int curMax = 0;

		if (s.length() <= 1)  return 0;

		for (int i = 1; i < s.length(); i++) { //直接默认longest[0]=0
			if (s[i] == ')'){
				if (s[i - 1] == '(') {
					longest[i] = i - 2 >= 0 ? longest[i - 2] + 2 : 2;
					//此处巧妙的解决了longest[1]==2的问题!!!
					curMax = max(longest[i], curMax);
				}

				else {
					if ((i - longest[i - 1] - 1) >= 0 && s[i - longest[i - 1] - 1] == '(') {
						longest[i] = longest[i - 1] + 2 + ((i - longest[i - 1] - 2) >= 0 ? longest[i - longest[i - 1] - 2] : 0);
						//此处同样用了条件运算符
						curMax = max(longest[i], curMax);
					}
				}
			}
		}
		return curMax;
	}
};

int main()
{
	int l;
	string s;
	Solution Obj;
	cout << "请输入一个只包含'('和')'的字符串：" << endl;
	cin >> s;
	l = Obj.longestValidParentheses(s);
	cout << l << endl;

	system("pause");
	return 0;
}