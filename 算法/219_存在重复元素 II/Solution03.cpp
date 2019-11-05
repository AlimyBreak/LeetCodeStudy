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
                map<int,int>  mii;
                for(int i = 0 ; i < nums.size();i++)
                {
                    if(mii.count(nums[i]))
                    {
                        if(i - mii[nums[i]] <=k)
                        {
                            return true;
                        }
                        else
                        {
                            mii[nums[i]] = i;
                        }
                    }
                    else
                    {
                        mii[nums[i]] = i;
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
执行用时 :56 ms, 在所有 cpp 提交中击败了39.80% 的用户
内存消耗 :15.3 MB, 在所有 cpp 提交中击败了28.08%的用户
*/