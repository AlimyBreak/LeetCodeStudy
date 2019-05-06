/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
示例 1:

输入: 121
输出: true

示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。


进阶(进阶并没有实现):
你能不将整数转为字符串来解决这个问题吗？
*/

/*
执行用时 : 48 ms, 在Palindrome Number的C++提交中击败了96.22% 的用户
内存消耗 : 8.1 MB, 在Palindrome Number的C++提交中击败了83.31% 的用户
*/
class Solution {
    #define MAXVALUELIMIT (2147483647/10)
public:
    bool isPalindrome(int x) {
        bool ret_val = false;
        char overflow_flag = 0 ;
        
        do{
            if(x<0)
            {
                ret_val = false;
                break;
            }
            
            int temp = x;
            int y    = 0;
            while(x!=0)
            {
                if(y>MAXVALUELIMIT)
                {
                    overflow_flag = 1;
                    break;
                }
                y = y*10 + x % 10;
                x /= 10;
            };
            if(overflow_flag == 1)
            {
                ret_val = false;
            }
            else
            {
                ret_val = (temp==y);
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
   cout << solution.isPalindrome(-2147483648) << endl;
   cout << solution.isPalindrome(8) << endl;
   cout << solution.isPalindrome(110)        << endl;
   cout << solution.isPalindrome(121)  << endl;
   return 0;
}



