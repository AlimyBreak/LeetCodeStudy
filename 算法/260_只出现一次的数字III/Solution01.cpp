class Solution
{
    public:
        vector<int> singleNumber(vector<int>& nums)
        {
            vector<int>             ret_val         ;
            map<int,int>            mii             ;
            int                     i               ;
            map<int,int>::iterator  iter            ;
            
            for( i = 0; i < nums.size() ; i++)
            {
                if(mii.count(nums[i])==1)
                {
                    mii[nums[i]] = 2;
                }
                else
                {
                    mii[nums[i]] = 1;
                }
            }
            
            iter = mii.begin();
            while(iter!=mii.end())
            {
                if(iter->second == 1)
                {
                    ret_val.push_back(iter->first);
                }
                iter++;
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :24 ms, 在所有 C++ 提交中击败了35.58% 的用户
内存消耗 :10.9 MB, 在所有 C++ 提交中击败了5.50%的用户
*/