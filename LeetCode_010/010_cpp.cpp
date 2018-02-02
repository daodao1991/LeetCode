#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		/* p的每种情况都要考虑s是否为空 */

		/*p.size() = 0*/
		if (p.empty())
		{
			return s.empty();
		}

		/*p.size() = 1*/
		if (p.size() == 1)
		{
			return (s.size() == 1 && (p[0] == s[0] || p[0] == '.'));
		}

		/*p.size() >= 2*/
		if (p[1] != '*')
		{
			if (s.empty())  return false;

			if (p[0] == s[0] || p[0] == '.')
				return isMatch(s.substr(1), p.substr(1));
			else
				return false;
		}
		else
		{
			while (!s.empty() && (p[0] == s[0] || p[0] == '.'))
			{
				if (isMatch(s, p.substr(2)))   return true;
				s = s.substr(1);
			}
			return isMatch(s, p.substr(2));
		}
	}
};

int main()
{
	string a, b;
	Solution Obj;
	bool boolstatus;

	cin >> a >> b;

	boolstatus = Obj.isMatch(a, b);
	cout << boolstatus << endl;

	system("pause");
	return 0;

}