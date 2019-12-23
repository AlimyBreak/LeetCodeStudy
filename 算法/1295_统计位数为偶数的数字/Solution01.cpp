class Solution
{
    public:
        int findNumbers(vector<int>& nums) 
        {
            int ret_val = 0;
            for(int i = 0 ; i < nums.size();i++)
            {
                if(nums[i]!=0)
                {
                    string s = to_string(nums[i]);
                    int length = s.size();
                    if(length % 2 == 0)
                    {
                        ret_val++;
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
执行用时 :12 ms, 在所有 cpp 提交中击败了100.00% 的用户
内存消耗 :9 MB, 在所有 cpp 提交中击败了100.00%的用户
*/