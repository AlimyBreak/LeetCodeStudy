class Solution
{
    private:   
        void mark(string& S, int* arr,int length)
        {
            int level   =   0;
            int i       =   0;
            char temp   =   0;
            
            stack<char> sc;
            for(i = 0;i<length;i++)
            {
                if(sc.empty()==true)
                {
                    level = 1;
                    sc.push(S.at(i));
                    arr[i] = level;
                }
                else
                {
                    if(S.at(i)=='(')
                    {
                        level++;
                        sc.push(S.at(i));
                        arr[i] = level;
                    }
                    else
                    {
                        sc.pop();
                        arr[i]=level;
                        level--;
                    }
                }
            }
        }
public:
    string removeOuterParentheses(string S)
    {
        string  ret_val                                         ;
        int     original_length =   S.length()                  ;
        int*    mark_level      =   new int[original_length]    ;
        int     i               =   0                           ;
        
        /*标注括号层级*/
        mark(S,mark_level,original_length);
        for(i = 0; i < original_length ; i++)
        {
            if(mark_level[i]>1)
            {
                ret_val += S[i];
            }
        }
        delete[] mark_level;
        return ret_val;
    }
};


/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了96.67% 的用户
内存消耗 :9.5 MB, 在所有 C++ 提交中击败了19.21%
*/