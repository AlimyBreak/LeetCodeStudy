/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
示例 1:
输入: 123
输出: 321
 示例 2:
输入: -123
输出: -321
示例 3:
输入: 120
输出: 21
注意:
假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
*/

/*
执行用时 : 12 ms, 在Reverse Integer的C++提交中击败了98.18% 的用户
内存消耗 : 8.4 MB, 在Reverse Integer的C++提交中击败了74.72% 的用户
*/
class Solution {
public:
    int reverse(int x) 
    {
        int p_or_n        = 0               ;
        int overflow_flag = 0               ;
        int maxvalueLimit = 2147483647/10   ;
        int ret_val       = 0               ;
        do{
            if(  (x == -2147483648  )
               ||(x == 0            )
            )
            {
                ret_val = 0;
                break;
            }
            p_or_n  = x > 0 ? 1:-1; /* 1为正,-1为负数 */
            x       = x*p_or_n;
            ret_val = 0;
            while(x!=0)
            {
                if(ret_val>maxvalueLimit)
                {
                    overflow_flag = 1;
                    break;
                }
                ret_val = ret_val*10 + x % 10;
                x /= 10;
            }
            if(overflow_flag == 0)
            {
                ret_val = ret_val * p_or_n;
                break;
            }
            else
            {
                return 0;
            }
            break;
        }while(0);
        return ret_val;
    }
};

#include <iostream>
using namespace std;

int main(void)
{
   Solution solution; 
   cout << solution.reverse(-2147483648) << endl;
   cout << solution.reverse(-2147483647) << endl;
   cout << solution.reverse(-110)        << endl;
   cout << solution.reverse(2147483641)  << endl;
   return 0;
}



