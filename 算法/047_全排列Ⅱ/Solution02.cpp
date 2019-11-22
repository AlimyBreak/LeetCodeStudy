// https://leetcode-cn.com/problems/permutations-ii/
// https://www.bilibili.com/video/av76286065

class Solution
{
    private:
        void helper(    vector<vector<int>>&    vvi,
                        vector<int>&            cur,
                        vector<int>&            nums,
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
                
                /* 跳过与上一个重复的,最基本的重复情况就是重复两个*/
                if(i > 0 && nums[i] == nums[i-1] && !visited[i-1]) //
                {
                    continue;
                }
                
                cur.push_back(nums[i]);         /* choose*/
                visited[i] = 1;
                helper(vvi,cur,nums,visited);   /* explore*/
                visited[i] = 0;                 /* unchoose*/
                cur.pop_back();

            }
            
        }
        
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums)
        {
            vector<vector<int>> vvi                     ;
            vector<int>         cur                     ;
            vector<int>         visited(nums.size(),0)  ;
            if(nums.size() < 1)
            {
                return vvi;
            }
            /*先排序一下*/
            sort(nums.begin(),nums.end());
            helper(vvi,cur,nums,visited);            
            return vvi;

        }
};

/*
执行结果：
通过
显示详情
执行用时 :28 ms, 在所有 cpp 提交中击败了93.70% 的用户
内存消耗 :9.8 MB, 在所有 cpp 提交中击败了93.27%的用户
*/