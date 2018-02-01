#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

class solution {
public:
	int myAtoi(string str)
	{
		int flag = 1, i = 0, num = 0, n = str.size();

		if (str.empty())  return 0;

		while (str[i] == ' ' && i < n)  ++i;

		while (str[i] == '+' || str[i] == '-')
		{
			flag = (str[i] == '+') ? 1 : -1;
			i++;
		}


		for (;i < n;i++)
		{

			if (!isdigit(str[i]))
			{
				continue;
			}

			if (num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10))
			{
				return (flag == 1) ? INT_MAX : INT_MIN;
			}

			if (str[i] >= '0' && str[i] <= '9')
			{
				num = num * 10 + str[i] - '0';
			}
		
		}

		num = num * flag;
		return num;

	}
};


int main()
{
	int r = 0;
	string word;
	solution Obj;

	cin >> word;

	r = Obj.myAtoi(word);
	cout << r << endl;

	system("pause");
	return 0;
}