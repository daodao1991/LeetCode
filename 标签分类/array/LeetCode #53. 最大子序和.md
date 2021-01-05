@[TOC](LeetCode #53. 最大子序和)

## I. Description：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210105141908151.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2Rhb2RhbzE5OTE=,size_16,color_FFFFFF,t_70#pic_center)
## II. Solution：
<br>

### version 1
<br>

##### 解题思路：
&emsp;&emsp;通过这道题开始尝试动态规划的算法思想。动态规划的思想主要是利用历史记录来避免一些重复计算，这些历史记录通常是用一维数组或二维数组来保存的。做动态规划题的三个重要步骤总结如下：

 - **定义数组元素的含义**
上面说到会用一维或二维数组来记录历史记录，假设用一维数组dp[ ]吧，一个非常重要的点就是规定数组中的元素代表什么意思。
 - **找出数组元素间的关系式**
动态规划跟高中数学中的归纳法有些相似，当前状态下的值往往跟之前的状态存在很大的关联性，当我们要计算dp[n]时，是可以利用dp[n-1]、dp[n-2]、...、dp[0]来推出dp[n]的，也就是利用历史数据来推出新的元素值，因此我们需要找出元素之间的关系式，例如dp[n] = dp[n-1] + dp[n-2]。这一步也是最难的一步。
 - **确定初始值**
当确定出了数组元素之间的关系式，一步一步推算下去之后，当不能再分解下去的时候，例如dp[n] = dp[n-1] + dp[n-2]，一直推算下去会有dp[2] = dp[1] + dp[0]，则dp[1]和dp[0]是必须直接能够确定的，这就是初始值了。

&emsp;&emsp;有了初始值，并且知道数组元素之间的关系式，我们便能得到dp[n]的值了。而dp[n]的值是什么是由你来定义的，你想求什么就可以把数组元素定义为什么，这样这道题也就解出来了。

&emsp;&emsp;在这道题中，我们定义一个数组dp[ ]来保存历史记录，其中dp[ i ]的含义定义为：**以当前数组元素nums[i]作为结尾的连续子数组的最大和**。因此，我们只需要求出每个位置上的dp[ i ]的值，然后返回这个数组中的最大值就好了。  如何求dp[i] ？可以考虑nums[i]独立为一段，还是加入dp[i - 1]对应的那一段，这取决于nums[i]和dp[i-1] + nums[i]的大小，由此可以写出这样的动态规划转移方程：
                        $dp[i] = max${ $dp[i - 1] + nums[i], nums[i]$ }
<br>
##### Code:

 - **cpp**
 

```cpp
#include <algorithm> //std::max
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        /*使用动态规划的思想来求解，即先定义出一个一维数组dp[]来保存历史记录*/
        // DP[i]定义为数组中以nums[i]为结尾的最大的连续子数组的和
        int len = (int)nums.size();
        vector<int> DP(len);
        DP[0] = nums[0];
        int res = nums[0];

        for (int i = 1; i < len; i++) {
            DP[i] = max(nums[i], DP[i-1] + nums[i]);
            res = res > DP[i] ? res : DP[i];
        }

        return res;
    }
};
```

