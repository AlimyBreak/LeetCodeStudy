

class Solution
{
    private:
    
        
        void helper(    vector<vector<int>>&    vvi     ,
                        vector<int>&            nums    ,
                        vector<int>&            cur_vi  ,
                        int                     idx
        )
        {
            vvi.push_back(cur_vi);  /* right 全不选依次保存*/
            
            for(int i = idx ; i < nums.size() ; i++)
            {
                /* idx的时候还是需要的*/
                if(    i > 0 
                    && nums[i] == nums[i-1]  
                    && i > idx
                )
                {
                    continue;
                }
                cur_vi.push_back(nums[i]);
                helper(vvi,nums,cur_vi,i+1);
                cur_vi.pop_back();
            }
        }

    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums)
        {

            vector<vector<int>>   vvi;
            if (nums.size() < 1)
            {
                return vvi;
            }
            vector<int> cur_vi;
            sort(nums.begin(), nums.end());
            helper(vvi, nums, cur_vi, 0);
            return vvi;

        }
};

/*
执行结果：
通过
显示详情
执行用时 :12 ms, 在所有 cpp 提交中击败了82.24% 的用户
内存消耗 :9 MB, 在所有 cpp 提交中击败了97.02%的用户
*/
