class Solution
{
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums)
        {
            map<int,int> mii;
            vector<int> ret;
            int i = 0;
            for(i=0;i<nums.size();i++)
            {
                mii[nums[i]] = 1;
            }
            
            for(i=1;i<=nums.size();i++)
            {
                if(mii.count(i)==0)
                {
                    ret.push_back(i);
                }
            }
            return ret;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :228 ms, 在所有 cpp 提交中击败了24.36%的用户
内存消耗 :27.9 MB, 在所有 cpp 提交中击败了5.18%的用户
*/