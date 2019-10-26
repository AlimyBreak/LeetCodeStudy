class Solution
{
    public:
        int singleNonDuplicate(vector<int>& nums)
        {
            /*
                时间复杂度 O(n)
                空间复杂度 O(1)
            */
            int ret_val = 0x00              ;
            int i       = 0                 ;
            int left    = 0                 ;
            
            for(i=0;i<nums.size();i+=2)
            {
                if(i+1<nums.size())
                {
                    if(nums[i]!=nums[i+1])
                    {
                        ret_val = nums[i];
                        break;
                    }
                }
                else
                {
                    ret_val = nums[i];
                    break;
                }
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :12 ms, 在所有 cpp 提交中击败了76.04% 的用户
内存消耗 :9.5 MB, 在所有 cpp 提交中击败了6.19%的用户
*/