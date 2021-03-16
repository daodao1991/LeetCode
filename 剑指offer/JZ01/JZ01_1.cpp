#include <iostream>
#include <vector>

/*暴力枚举*/

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int>> array) {
        if (array.size() == 0 || array[0].size() == 0) {
            return false;
        }

        for (const auto& vec : array) {
            for (const auto item : vec) {
                if (item == target) {
                    return true;
                }
            }
        }
    }
};