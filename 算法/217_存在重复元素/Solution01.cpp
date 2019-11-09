class Solution 
{
    public:
        bool containsDuplicate(vector<int>& nums)
        {
            map<int,int> mii;
            int i = 0;
            for(i = 0 ; i < nums.size() ; i++)
            {
                mii[nums[i]] = 0;
            }
            return mii.size() == nums.size();
        }
};


/*
执行结果：
通过
显示详情
执行用时 :40 ms, 在所有 cpp 提交中击败了77.81% 的用户
内存消耗 :18.1 MB, 在所有 cpp 提交中击败了5.09%的用户
*/