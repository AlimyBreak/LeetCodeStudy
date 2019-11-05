class Solution
{
    
    private:
        /* (left,right]*/
        bool haveSame(vector<int>& nums,int left , int right)
        {
            int     i       = 0     ;
            for(i = left+1;i<=right;i++)
            {
                if(nums[left]==nums[i])
                {
                    return true;
                }
            }
            return false;
        }    
    
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k)
        {
            int right = 0           ;
            int i     = 0           ;
            int len   = nums.size() ;
            for(i = 0;i<len;i++)
            {
                right = (i+k < len)? (i+k) : (len-1);
                if(haveSame(nums,i,right))
                {
                    return true;
                }
            }
            
            return false;
            
        }
};

/*
22 / 23 个通过测试用例
	状态：超出时间限制
    
*/