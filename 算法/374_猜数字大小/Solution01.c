
/*
我们正在玩一个猜数字游戏。 游戏规则如下：
我从 1 到 n 选择一个数字。 你需要猜我选择了哪个数字。
每次你猜错了，我会告诉你这个数字是大了还是小了。
你调用一个预先定义好的接口 guess(int num)，它会返回 3 个可能的结果（-1，1 或 0）：

-1 : 我的数字比较小
 1 : 我的数字比较大
 0 : 恭喜！你猜对了！
示例 :
输入: n = 10, pick = 6
输出: 6
*/


// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);


/*
基本思路：二分查找
注意事项：防止加法溢出。
*/
class Solution {
public:
    int guessNumber(int n) 
    {
        int ret_val = 0;
        int left    = 1;
        int right   = n;
        int mid     = 0;
        
        while(left <= right)
        {
            mid     = left + (right-left)/2; /* 经典的两个正整数相加取平均数防溢出的写法 */
            ret_val = guess(mid);
            if(ret_val==0)
            {
                ret_val = mid;
                break;
            }
            else if(ret_val < 0 )
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        
        return ret_val;
    }
};


/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C++ 提交中击败了34.75% 的用户
内存消耗 :8.1 MB, 在所有 C++ 提交中击败了64.30%的用户
*/