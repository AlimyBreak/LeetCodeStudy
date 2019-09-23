class Solution
{
    public:
        vector<vector<int>> combine(int n, int k)
        {
            vector<int>         ans                         ;
            vector<int>         temp                        ;
            vector<vector<int>> ret_val                     ;
            int                 size_pow    =   pow(2,n)    ;
            unsigned int        i           =   0           ;
            unsigned int        j           =   0           ;
            
            for( i = 1; i <= n ;i++)
            {
                ans.push_back(i);
            }
            
            for( i = 0 ; i < size_pow ; i++)
            {
                temp.clear();
                for( j = 0; j < n ; j++)
                {
                    if( i & ( 0x01 << j))
                    {
                        temp.push_back(ans[j]);
                    }
                }
                
                if(temp.size() == k )
                {
                    ret_val.push_back(temp);
                }
            }
            
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :204 ms, 在所有 C++ 提交中击败了33.93% 的用户
内存消耗 :11.8 MB, 在所有 C++ 提交中击败了70.26%的用户
*/