#include<iostream>
#include<stdlib.h>
#include<string>
#include<stdio.h>   //sprintf()包含于该头文件中

using namespace std;


class Solution{
public:
	string countAndSay(int n){
		if(n == 1)
			return "1";
		if(n == 2)
			return "11";
		return say(countAndSay(n - 1));
	}

private:
	string say(string s){
		int i = 0, j = 0, count = 1;
		string ans;

		while(i < s.size()) {
			j = i + 1;
			if(j == s.size()) {
				ans += to_string(count) + s[i];
				break;
			}
			if(s[j] == s[i]) {
				count++;
				i++;
			} 
			else {
				ans += to_string(count) + s[i];
				count = 1;
				i++;
			}
		}
		return ans;
	}
};

int main(){
	int n;
	char s[100];
	Solution obj;

	cout << "请输入一个整数：" << endl;
	cin >> n;
	sprintf(s,"第%d个数对应的输出为：",n);
	cout << obj.countAndSay(n) << endl;
	return 0;
}
