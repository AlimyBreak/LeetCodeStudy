class Solution
{
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums)
        {
            vector<int> ret;
            int i = 0;
            for(i=0;i<nums.size();i++)
            {
                if(nums[abs(nums[i])-1] >0)
                {
                    nums[abs(nums[i])-1] *= -1;
                }
            }
            
            for(i=0;i<nums.size();i++)
            {
                if(nums[i] > 0)
                {
                    ret.push_back(i+1);
                }                    
            }
            return ret;
        }
};
/*
执行结果：
通过
显示详情
执行用时 :120 ms, 在所有 cpp 提交中击败了90.19% 的用户
内存消耗 :14.8 MB, 在所有 cpp 提交中击败了88.05%的用户
*/