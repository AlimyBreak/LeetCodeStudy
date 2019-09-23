class Solution
{
    private:
        int numOfbit1(unsigned int  d)
        {
            int count=0;
            for(; d; d &= d - 1)
            {
                count++;
            }
            return count;
        }
    public:
        vector<vector<int>> combine(int n, int k)
        {
            vector<int>         ans                         ;
            vector<int>         temp                        ;
            vector<vector<int>> ret_val                     ;
            int                 size_pow    =   pow(2,n)    ;
            unsigned int        i           =   0           ;
            unsigned int        j           =   0           ;
            
            for(i = 0; i < n ;i++)
            {
                ans.push_back(i+1);
            }

            for( i = 0 ; i < size_pow ; i++)
            {
                if(numOfbit1(i)==k)
                {
                    temp.clear();
                    for( j = 0; j < n ; j++)
                    {
                        if( i & ( 0x01 << j))
                        {
                            temp.push_back(ans[j]);
                        }
                    }
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
执行用时 :88 ms, 在所有 C++ 提交中击败了98.18% 的用户
内存消耗 :11.9 MB, 在所有 C++ 提交中击败了67.91%的用户
*/