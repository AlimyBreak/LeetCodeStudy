class Solution
{
    public:
        int maxSubArray(vector<int>& nums)
        {
            int ret_val = 0;
            int temp    = 0;
            
            if(nums.size()<1)
            {
                return 0;
            }
            
            int right_max   =   nums.size()-1   ;
            int i           =   0               ;
            
            ret_val = nums[0];
            for(i = 0 ; i <= right_max ; i++)
            {
                if(temp > 0)
                {
                    temp += nums[i];
                }
                else
                {
                    temp = nums[i];
                    
                }
                
                if(temp > ret_val)
                {
                    ret_val = temp;
                }
            }            
            return ret_val;

        }
};



