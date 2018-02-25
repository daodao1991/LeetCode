#include<iostream>
#include<string>
#include<stack>
#include<stdlib.h>

using namespace std;

class Solution {
public:
	bool isValidParentheses(string s)
	{
		stack<char> stk;

		for (int i = 0; i != s.size(); ++i)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				stk.push(s[i]);
			}

			else if (stk.empty())  return false;

			else if (s[i] == ')' && stk.top() != '(')  return false;

			else if (s[i] == ']' && stk.top() != '[')  return false;

			else if (s[i] == '}' && stk.top() != '{')  return false;

			else
				stk.pop();

		}

		return stk.empty();
	}
};


int main()
{
	string str;
	Solution Obj;
	bool a;

	cout << "请输入一个只包含括号的字符串" << endl;
	cin >> str;

	a = Obj.isValidParentheses(str);
	cout << a << endl;

	system("pause");
	return 0;
}