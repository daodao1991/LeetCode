#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		vector<int> longest(s.length());  //Ĭ�Ϲ��캯��ÿ��Ԫ����0
		int curMax = 0;

		if (s.length() <= 1)  return 0;

		for (int i = 1; i < s.length(); i++) { //ֱ��Ĭ��longest[0]=0
			if (s[i] == ')'){
				if (s[i - 1] == '(') {
					longest[i] = i - 2 >= 0 ? longest[i - 2] + 2 : 2;
					//�˴�����Ľ����longest[1]==2������!!!
					curMax = max(longest[i], curMax);
				}

				else {
					if ((i - longest[i - 1] - 1) >= 0 && s[i - longest[i - 1] - 1] == '(') {
						longest[i] = longest[i - 1] + 2 + ((i - longest[i - 1] - 2) >= 0 ? longest[i - longest[i - 1] - 2] : 0);
						//�˴�ͬ���������������
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
	cout << "������һ��ֻ����'('��')'���ַ�����" << endl;
	cin >> s;
	l = Obj.longestValidParentheses(s);
	cout << l << endl;

	system("pause");
	return 0;
}