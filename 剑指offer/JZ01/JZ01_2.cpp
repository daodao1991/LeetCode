#include <vector>
#include <iostream>

using namespace std;

/* ######################################## 解题思路 ########################################################## */

/*     把每一行看做是有序递增的数组，对每一行使用二分查找,下面给出两种二分查找的写法，其中推荐使用第二种写法，
/* 该写法可以适用于区间为空、答案不存在、有重复元素、搜索开/闭的上/下界等情况*/


// Solution 1
class Solution_1 {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.size() == 0 || array[0].size() == 0) return false;

        for (const auto& vec : array) {
            int mid = 0, left = 0, right = array.size();

            while (left <= right) {
                mid = left + (right - left) / 2;
                
                if (target > mid) {
                    left = mid +1;
                }
                else if (target < mid) {
                    right = mid -1;
                }
                else {
                    return true;
                }
            }
        }

        return false;
    }
};


// Solution 2
/*      这种写法的诀窍在于搜索区间[first, last)使用的是左闭右开，这种方式的好处是符合直觉，同时可以省去代码中太多的 +1/-1 操作；
    同时，取中间的方式使用的是mid = first + (last - first) / 2, 这种方式较之 mid = (first + last) /2的好处是防止溢出；
    可以从while循环中的循环不变量来理解该写法的思路，即进入while循环中一定成立的条件如下：
    1. 搜索区间[first, last)不为空，即满足first < last
    2. 搜索区间[first, last)左侧，即[first0, first)范围内的所有元素都小于target, 其中first0是first的初始值；
    3. 搜索区间[first, last)右侧，即[last, last0)范围内的所有元素都大于target，其中last0是last的初始值。

        有了以上的认识，便可以理解代码中左右边界的调整：当中间值小于target时，说明此时的mid应该位于搜索区间的左侧，为了最大限度的减少搜索
    范围且不包含mid，则应该将左侧边界first = mid + 1; 当中间值大于等于target时，说明此时的mid应该位于搜索区间的右侧，为最大限度的减少搜
    索区间且不包含mid，则将右侧边界调整到mid处，即last = mid，这样更新后的范围仍然是不包含原来的mid的。

        需要注意的是，这种写法求解的是 >=target 这个区间的下界，即满足 x >= target 条件的最小的x的位置，若这样的存在则最后返回first和last
    都一样，因为最后二者会重合，若这样的值不存在，则最后返回的last0，即初始范围之后的第一个元素；若要求的是任意等于target值的位置，只需要在
    调整搜索区间[first, last)之前，判断一下当前中间值是否等于中间值即可。
*/
class Solution_2 {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.size() == 0 || array[0].size() == 0) return false;
        
        for (const auto& vec : array) 
        {
            int mid = 0, first = 0, last = array.size();
            while (first < last) {
                mid = first + (last - first) / 2;
                if (vec[mid] == target) {
                    return true;
                }
                
                if (vec[mid] < target) {
                    first = mid + 1;
                } else {
                    last = mid;
                }
            }
        }
        
        return false;
    }
};