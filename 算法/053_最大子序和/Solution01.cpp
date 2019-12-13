class Solution
{
    
    private:
    
        void helper(    int&            ret_val     ,
                        int             begin       ,
                        vector<int>&    nums        ,
                        int&            right_max
                   )
        {
            int part_sum = 0;
            for(int i = begin ; i <= right_max ; i++)
            {
                part_sum += nums[i];
                if(part_sum>ret_val)
                {
                    ret_val = part_sum;
                }
            }
            
        }
    
    public:
        int maxSubArray(vector<int>& nums)
        {
            int ret_val = -2147483648;
            if(nums.size()<1)
            {
                return 0;
            }
            
            int right_max   =   nums.size()-1   ;
            int i           =   0               ;
            
            for(i = 0 ; i <= right_max ; i++)
            {
                helper(ret_val,i,nums,right_max);                
            }            
            return ret_val;

        }
};

/*
执行结果：
通过
显示详情
执行用时 :512 ms, 在所有 cpp 提交中击败了5.00% 的用户
内存消耗 :9.1 MB, 在所有 cpp 提交中击败了95.17%的用户
*/