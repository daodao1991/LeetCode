#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		int div = 1;
		int left, right;
		int flag = 1;

		if (x < 0)  return false;

		while (x / div >= 10)
		{
			div *= 10;
		}

		while (x > 0)
		{
			left = x / div;
			right = x % 10;
			if (left != right)
			{
				return false;
			}
			else
			{
				x = (x % div) / 10;
				div /= 100;
			}
		}

		return true;
	}
};


int main()
{
	int a;
	bool boolstatus;
	Solution Obj;
	
	cin >> a;
	boolstatus = Obj.isPalindrome(a);
	cout << boolstatus<< endl;

	system("pause");
	return 0;
}