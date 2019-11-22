// https://leetcode-cn.com/problems/subsets/submissions/
// https://www.bilibili.com/video/av76286065

class Solution
{
    private:
        void helper(    vector<vector<int>>&    vvi,
                        vector<int>&            cur,
                        vector<int>&            nums,
                        int                     index
                   )
        {
            if(index == nums.size())
            {
                vvi.push_back(cur);
                return;
            }
            
            cur.push_back(nums[index]);
            helper(vvi,cur,nums,index+1);
            cur.pop_back();
            helper(vvi,cur,nums,index+1);
        }
    
    public:
        vector<vector<int>> subsets(vector<int>& nums)
        {
            vector<vector<int>> vvi;
            vector<int>         cur;
            
            if(nums.size() < 1)
            {
                return vvi;
            }
            helper(vvi,cur,nums,0);
            return vvi;
        }
};



/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 cpp 提交中击败了99.78% 的用户
内存消耗 :12.7 MB, 在所有 cpp 提交中击败了11.02%的用户
*/