/*
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
    I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
    X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
    C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
示例 1:
输入: "III"
输出: 3
示例2:
输入: "IV"
输出: 4
示例 3:
输入: "IX"
输出: 9
示例 4:
输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.
示例 5:
输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
*/

/*
*/


class Solution {
public:
    int romanToInt(string s)
    {
        int  n            = s.length()  ;
        int  ret_val      = 0           ;
        char level_new    = 0           ;/* 1,2,3,4,5,6,7*/
        int  level_old    = 0           ; /*状态机需要的两个变量*/
        int  value        = 0           ;
        int  level_sum    = 0           ;
        for(int i = 0; i < n ; i++)
        {
            level_old = level_new;
            char2int(s.charAt(i),level_new,value);
            
            if(level_old == 0)
            {
                level_sum += value;
                continue;
            }
            
            if(level_old == level)
            
            
            
            
            
        }
    }
    
    void char2int(char ch, char& level,char value)
    {
        switch(ch)
        {
            case 'I': //1
                value = 1;
                level = 1;
            break;
            case 'V': //5
                value = 5;
                level = 2;
            break;
            case 'X': //10
                value = 10;
                level = 3;
            break;
            case 'L': //50
                value = 50;
                level = 4;
            break;
            case 'C': //100
                value = 100;
                level = 5;
            break;
            case 'D': //500
                value = 500;
                level = 6;
            break;
            case 'M': //1000
                value = 500;
                level = 7;
            break;
            default:
                value = 0;
                level = -1;
            break;
        }
    }
};

#include <iostream>
using namespace std;

int main(void)
{
   Solution solution; 
   cout << solution.romanToInt("III")   << endl;
   cout << solution.romanToInt("IV")    << endl;
   cout << solution.romanToInt("IX")    << endl;
   cout << solution.romanToInt("IX")    << endl;
   return 0;
}



