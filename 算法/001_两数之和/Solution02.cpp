class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            vector<int>         ret_val         ;
            map<int,int>        mii             ;
            int                 i       =   0   ;

            for(i=0;i<nums.length();i++)
            {
                if(mii.count(target-nums[i]) == 1)  /*已经有了一个*/
                {
                    ret_val.push_back(i);
                    ret_val.push_back(mii[target-nums[i]]);
                    break;
                }
                mii[nums[i]] = i;
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C++ 提交中击败了98.87% 的用户
内存消耗 :10.2 MB, 在所有 C++ 提交中击败了28.47%的用户
*/