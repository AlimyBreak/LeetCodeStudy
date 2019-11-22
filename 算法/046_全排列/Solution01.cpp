class Solution
{
    private:
        vector<vector<int>> ret_val;
        void __rank(    vector<int>& nums       ,
                        vector<int> level_rank
                   )
        {
            if(nums.size() == 1)
            {
                level_rank.push_back(nums[0]);
                ret_val.push_back(level_rank);
                return ;
            }
            for(int i = 0; i < nums.size() ; i++)
            {
                vector<int> temp;
                for(int j = 0 ; j < nums.size() ; j++)
                {
                    if(i!=j)
                    {
                        temp.push_back(nums[j]);
                    }
                    else
                    {
                        level_rank.push_back(nums[j]);
                    }
                }
                __rank(temp,level_rank);
                level_rank.pop_back();
            }
        }
        
    public:
        vector<vector<int>> permute(vector<int>& nums)
        {
            ret_val.clear();
            vector<int> temp;
            if(nums.size() !=0)
            {
                __rank(nums,temp);
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :20 ms, 在所有 C++ 提交中击败了63.44% 的用户
内存消耗 :10.4 MB, 在所有 C++ 提交中击败了10.14%的用户
*/