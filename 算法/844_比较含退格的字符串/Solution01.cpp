class Solution
{
    public:
        bool backspaceCompare(string S, string T)
        {
            stack<char> scs;
            stack<char> sct;
            int     i           =   0       ;
            int     size        =   0       ;
            bool    ret_val     =   true    ;
        
            size = S.size();
            for(i=0;i<size;i++)
            {
                if(S.at(i)=='#')
                {
                    if(!scs.empty())
                    {
                        scs.pop();
                    }
                }
                else
                {
                    scs.push(S.at(i));
                }
            }
            
            size = T.size();
            for(i = 0;i<size;i++)
            {
                if(T.at(i)=='#')
                {
                    if(!sct.empty())
                    {
                        sct.pop();
                    }
                }
                else
                {
                    sct.push(T.at(i));
                }
            }
            
            do{
                
                if(scs.size() != sct.size())
                {
                    ret_val = false;
                    break;
                }
                
                while(!scs.empty())
                {
                    if(scs.top()!=sct.top())
                    {
                        ret_val = false;
                        break;
                    }
                    else
                    {
                        scs.pop();
                        sct.pop();
                    }
                }       
            }while(0);
            return ret_val;
    }
};


/*
执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :8.5 MB, 在所有 C++ 提交中击败了87.25%的用户
*/
