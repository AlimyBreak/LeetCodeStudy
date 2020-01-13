class Solution
{
    public:
        vector<int> decompressRLElist(vector<int>& nums)
        {
            int num = nums.size()/2;
            int i   = 0;
            int j   = 0;
            vector<int> ret_val;
            
            for(i = 0 ; i < num; i++)
            {
                for(j = 0 ; j < nums[2*i]; j++)
                {
                    ret_val.push_back(nums[2*i+1]);
                }
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :16 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :11.3 MB, 在所有 C++ 提交中击败了100.00%的用户
*/