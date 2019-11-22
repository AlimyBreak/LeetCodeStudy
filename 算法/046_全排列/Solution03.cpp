// https://leetcode-cn.com/submissions/detail/37429272/
// 回溯法 https://www.bilibili.com/video/av76286065


class Solution
{
    
    private:
    
        void helper(    vector<vector<int>>&    vvi     ,
                        vector<int>&            cur     ,
                        vector<int>&            nums    ,
                        vector<int>&            visited
                    )
        {
            if(cur.size() == nums.size())
            {
                vvi.push_back(cur);
                return;
            }
            
            
            for(int i = 0 ; i < nums.size() ; i++)
            {
                if(visited[i])
                {
                    continue;
                }
                else
                {
                    cur.push_back(nums[i]);             // choose
                    visited[i]  =   1;               
                    helper(vvi,cur,nums,visited);       // explore
                    visited[i]  =   0;                  // unchoose
                    cur.pop_back();
                }
                
            }
            
        }
    
    
    public:
        vector<vector<int>> permute(vector<int>& nums)
        {
            vector<vector<int>> vvi;
            vector<int>         cur;
            vector<int>         visited(nums.size(),0);
            
            if(nums.size() < 1)
            {
                return vvi;
            }
            helper(vvi, cur, nums , visited);
            return vvi;
            
        }
    
};

/*
执行结果：
通过
显示详情
执行用时 :24 ms, 在所有 cpp 提交中击败了33.40% 的用户
内存消耗 :9.1 MB, 在所有 cpp 提交中击败了88.83%的用户
*/