class Solution 
{
    
    public:
        vector<int> shortestToChar(string S, char C)
        {
            vector<int>  ret_val        ;
            vector<int>  temp_ind       ;
            int          i       =   0  ;
            int          j       =   0  ;
            int          min_ind =   0   ;
            
            /*找到S中所有C的索引*/
            for(i=0;i<S.size();i++)
            {
                if(C==S.at(i))
                {
                    temp_ind.push_back(i);
                }
            }
            
            /*遍历S中的每一个元素并计算*/
            for(i=0;i<S.size();i++)
            {
                min_ind = 10000;
                if(S.at(i)==C)
                {
                    min_ind = 0;
                }
                else
                {
                    for(j=0;j<temp_ind.size();j++)
                    {
                        if(abs( temp_ind[j] - i ) < min_ind)
                        {
                            min_ind = abs( temp_ind[j] - i );
                        }
                    }
                }
                ret_val.push_back(min_ind);
            }
            return ret_val;
        }
};


/*
执行结果:
通过
显示详情
执行用时 :20 ms, 在所有 C++ 提交中击败了47.42%的用户
内存消耗 :8.9 MB, 在所有 C++ 提交中击败了74.80%的用户
*/