#include <iostream>
#include <vector>

using namespace std;

/* ######################################## 解题思路 ########################################################## */

/*      这种思路相对比较巧妙，从数组本身每行从左到右递增、每列从上到下递增的特点出发，考虑从右上角或左下角出发不断去缩小搜索的范围。
    例如，将遍历的初始值value设定为左下角array[length-1][0]，当value < target时，说明要往较大的值去找，而当前value所在列上边的值
    都是小于它的，故可将该列舍去，更新value = array[row][++col];当value > target时，往较小的值去找，而当前value所在行的右侧的值
    都大于它，故可将该行舍去，将value = array[--row][col]
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.size() == 0 || array[0].size() == 0) return false;

        int m = array.size(), n = array[0].size();
        int row = m - 1, col = 0;


        while(row >=0 && col < n) {
            if (array[row][col] == target) {
                return true;
            }
            else if (array[row][col] > target) {
                row--;
            }
            else {
                col++;
            }
        }
    }
};