class Solution
{
    public:
        vector<int> findDuplicates(vector<int>& nums)
        {
            int i = 0;
            vector<int> ret_val ;
            
            for(i=0;i<nums.size();i++)
            {
                /*已经被置设置为负数过*/
                if(nums[abs(nums[i])-1] <0)
                {
                    ret_val.push_back(abs(nums[i]));
                }
                else
                {
                    nums[abs(nums[i])-1] *= -1;
                }
                
            }
            return ret_val;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :116 ms, 在所有 cpp 提交中击败了96.78% 的用户
内存消耗 :14.7 MB, 在所有 cpp 提交中击败了93.33%的用户
*/