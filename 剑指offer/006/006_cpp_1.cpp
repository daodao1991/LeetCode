#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/***************************************************
 ******************利用二分法查找*******************
 ***************************************************/

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray){
		int len = rotateArray.size();
		if(len == 0){
			return 0;
		}
		//设置左右两个指针，指向头和尾
		int left = 0, right = len - 1;
		int mid = 0;

		while(rotateArray[left] >= rotateArray[right]){	
			//当两个指针相邻时结束循环，right指的就是最小元素
			if(right - left == 1){
				mid = right;
				break;
			}

			int mid = left + (right - left) / 2;
			//如果中间元素和两端的元素，三者相等，则只能进行顺序查找
			if(rotateArray[left] == rotateArray[mid] &&
				rotateArray[left] == rotateArray[right]){
				return MinNumber_Order(rotateArray, left, right);
			}
			//中间元素位于前面的递增子数组,left后移
			if(rotateArray[mid] >= rotateArray[left]){
				left = mid;
			}
			//中间元素位于后面的递增子数组，right前移
			else{
				right = mid;
			}
		}//while
		
		return rotateArray[mid];
	}

private:
	//顺序查找
	int MinNumber_Order(vector<int> &num, int left, int right){
		int res = num[left];
		for(int i = left + 1;i < right;++i){
			if(num[i] < res){
				res = num[i];
			}
		}
		return res;
	}
}


int main(){
	Solution Obj;
	vector<int> vec = {1,1,1,1,1,0,1};
	int res = Obj.minNumberInRotateArray(vec);
	cout<<res<<endl;
	return 0;
}
