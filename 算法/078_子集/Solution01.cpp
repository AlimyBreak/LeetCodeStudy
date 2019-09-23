class Solution
{
    public:
        vector<vector<int>> subsets(vector<int>& nums)
        {
            vector<vector<int>> ret_val                         ;
            vector<int>         temp                            ;
            unsigned long int   i           = 0                 ;
            unsigned char       j           = 0                 ;
            unsigned long int   size        = nums.size()       ;
            unsigned long int   size_pow    = pow(2, size)      ;
            
            for (i = 0; i < size_pow; i++)
            {
                temp.clear();
                for (j = 0; j < size; j++)
                {
                    if (i & (0x01 << j))
                    {
                        temp.push_back(nums[j]);
                    }
                }
                ret_val.push_back(temp);
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C++ 提交中击败了91.24% 的用户
内存消耗 :9 MB, 在所有 C++ 提交中击败了84.04%的用户
*/
