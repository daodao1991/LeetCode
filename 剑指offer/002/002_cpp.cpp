#include<iostream>
#include<stdlib.h>

using namespace std;

class Solution {
public:
	//从前往后看，每遇到一个空格，后边的字符都要向后移动两位
	void replaceSpace(char *str,int length) {
		int count = 0;
		for(int i = 0; i < length; i++){
			if(str[i] == ' ')  count++;
		}
		//从后往前遍历，后边的字符往后移动的位置要比前边的大
		for(int j = length-1; j >= 0; j--){
			if(str[j] != ' '){
				str[j + count*2] = str[j];
			}
			else{
				count--;  //把空格和前面的字符连在一起看
				str[j + count*2] = '%';
				str[j + count*2 +1] = '2';
				str[j + count*2 +2] = '0';
			}
		}
	}
};
