class Solution
{

    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k)
        {
            if(nums.size()< 2)
            {
                return false;
            }
            else
            {
                map<int,vector<int>>  mivi;
                for(int i = 0 ; i < nums.size();i++)
                {
                    if(mivi.count(nums[i]))
                    {
                        mivi[nums[i]].push_back(i);
                        if(mivi[nums[i]][mivi[nums[i]].size()-1]- mivi[nums[i]][mivi[nums[i]].size()-2] <=k)
                        {
                            return true;
                        }
                    }
                    else
                    {
                        vector<int> vi;
                        vi.push_back(i);
                        mivi[nums[i]] = vi;
                    }
                }
            }
            return false;
            
        }
};

/*
执行结果：
通过
显示详情
执行用时 :64 ms, 在所有 cpp 提交中击败了25.25% 的用户
内存消耗 :22.4 MB, 在所有 cpp 提交中击败了5.03%的用户
*/