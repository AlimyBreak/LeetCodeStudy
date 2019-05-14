/*
给定一个[只包括] '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
示例 1:
输入: "()"
输出: true
示例 2:
输入: "()[]{}"
输出: true
示例 3:
输入: "(]"
输出: false
示例 4:
输入: "([)]"
输出: false
示例 5:
输入: "{[]}"
输出: true
*/

#include<stack> 
#include<string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        char match      = 0;
        char temp       = 0;
        int  len        = s.length();
        for(int i = 0;i <len;i++)
        {
            temp = s.at(i);
            if(sk.empty()==true)
            {
                sk.push(temp);
            }
            else
            {
                match = 0;
                switch(temp)
                {
                    case ')':
                        if(sk.top()=='(')
                        {
                            match = 1;
                        }
                    break;
                    case '}':
                        if(sk.top()=='{')
                        {
                            match = 1;
                        }
                    break;
                    case ']':
                        if(sk.top()=='[')
                        {
                            match = 1;
                        }  
                    break;
                    default:
                        //match = 0;
                    break;
                }
                
                if(match == 1)
                {
                    sk.pop();
                }
                else
                {
                    sk.push(temp);
                }
            }
        }
        return sk.empty();  
    }
};

int main(void)
{
    Solution solution;
    string s("{[]}");
    cout << solution.isValid(s) << endl;
    return 0;
}

/*
执行用时 : 8 ms, 在Valid Parentheses的C++提交中击败了97.02% 的用户
内存消耗 : 8.7 MB, 在Valid Parentheses的C++提交中击败了68.92% 的用户
76 / 76 个通过测试用例 状态：通过
*/