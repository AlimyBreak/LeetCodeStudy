class Solution
{
    public:
        vector<int> shortestToChar(string S, char C)
        {
            vector<int> ret_val ;
            int     len     =   S.size();
            int     i       =   0;
            int     left    =   0;
            int     right   =   0;
            char    ch      =   0;
            int     min_ind =   0;
            
            for(i = 0 ; i < len ; i++)
            {
                ch = S.at(i);
                if(ch == C)
                {
                    ret_val.push_back(0);
                }
                else
                {
                    left    = i - 1;
                    right   = i + 1;
                    while(1)
                    {
                        if(  ( left >=0)
                           &&( C == S.at(left))
                        )
                        {
                            ret_val.push_back(i-left);
                            break;
                        }
                        else
                        {
                            left--;
                        }
                        
                        if(   (right < len)
                            &&(C == S.at(right))
                        )
                        {
                            ret_val.push_back(right-i);
                            break;
                        }
                        else
                        {
                            right++;
                        }
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
执行用时 :12 ms, 在所有 C++ 提交中击败了96.01%的用户
内存消耗 :8.9 MB, 在所有 C++ 提交中击败了77.17%的用户
*/