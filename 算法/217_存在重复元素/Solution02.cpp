class Solution 
{
    public:
        bool containsDuplicate(vector<int>& nums)
        {
            sort(nums.begin(),nums.end());
            for(int i = 1; i < nums.size() ;i++)
            {
                if(nums[i] == nums[i-1])
                {
                    return true;
                }
            }
            return false;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :24 ms, 在所有 cpp 提交中击败了98.87% 的用户
内存消耗 :11.2 MB, 在所有 cpp 提交中击败了80.28%的用户
*/