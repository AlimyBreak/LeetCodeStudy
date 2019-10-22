class Solution
{
    public:
        vector<int> findDuplicates(vector<int>& nums)
        {
            map<int,int> mii;
            int i = 0;
            vector<int> ret_val ;
            
            for(i=0;i<nums.size();i++)
            {
                if(mii.count(nums[i]))
                {
                    ret_val.push_back(nums[i]);
                }
                else
                {
                    mii[nums[i]] = 1;
                }
            }
            
            return ret_val;
        }
};



/*
执行结果：
通过
显示详情
执行用时 :232 ms, 在所有 cpp 提交中击败了25.34%的用户
内存消耗 :27.8 MB, 在所有 cpp 提交中击败了5.55%的用户
*/