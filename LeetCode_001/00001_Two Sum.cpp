#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>

using namespace std;

/*****解题思路*****
    通过创建一个map容器，记录当前元素的互补值及当前的索引值；在后续的遍历中，
若有元素出现在了该map中便完成查找，同时获得第二个元素的索引值，第一个元素的
索引之前已经记录在map中了
*/

class Solution{
public: 
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> res;
        map<int, int>  M;
        map<int, int>::iterator iter_map;

        for(int i = 0; i != nums.size(); i++){
            iter_map = M.find(nums[i]);

            if(iter_map == M.end()){
                //map中未找到当前元素，则将其互补值和索引值存入map中
                M[target - nums[i]] = i;
            }
            else{
                //找到了对应的互补值
                int first_index = M[nums[i]];
                int second_index = i;

                res.push_back(first_index);
                res.push_back(second_index);

                break;
            }

        }

        return res;
    }

};


int main(){
    vector<int> result;
    Solution obj;

    vector<int> nums = {3, 2, 7, 5, 11, 9};
    int target = 13;

    result = obj.twoSum(nums, target);

    string pre = " Result: { ";
    cout << pre;
    for(int i = 0; i != result.size(); i++){
        cout << result[i] << ' ';
    }
    cout << '}' << endl;

    system("pause");
    return 0;
}