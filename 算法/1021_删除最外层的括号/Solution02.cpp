class Solution
{
    public:
        string removeOuterParentheses(string S)
        {
            string ret_val ;
            int original_length = S.length();
            int i               = 0;
            int level           = 0;
            stack<char> sc;
            
            for(i = 0; i < original_length ; i++)
            {
                if(sc.empty()==true)
                {
                    level = 1;
                    sc.push(S.at(i));
                }
                else
                {
                    if(S.at(i)=='(')
                    {
                        level++;
                        sc.push(S.at(i));
                        if(level>1)
                        {
                            ret_val += S.at(i);
                        }
                    }
                    else
                    {
                        sc.pop();
                        if(level>1)
                        {
                            ret_val += S.at(i);
                        }
                        level--;
                    }
                }
            }
            return ret_val;
            
        }
};

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了96.67% 的用户
内存消耗 :9 MB, 在所有 C++ 提交中击败了58.04%的用户
*/