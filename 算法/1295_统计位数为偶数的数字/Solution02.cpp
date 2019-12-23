class Solution
{
    public:
        int findNumbers(vector<int>& nums) 
        {
            int ret_val = 0;
            for(int i = 0 ; i < nums.size();i++)
            {
                int temp = nums[i];
                
                if(   (temp >= 10 && temp <= 99 )
                    ||(temp >= 1000 && temp <= 9999 )
                    ||(temp >= 100000 && temp <= 999999 )
                )
                {
                    ret_val++;
                }
                
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 cpp 提交中击败了100.00% 的用户
内存消耗 :8.7 MB, 在所有 cpp 提交中击败了100.00%的用户
*/