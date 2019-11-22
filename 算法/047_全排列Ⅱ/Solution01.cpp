class Solution
{
    
    private:
    
        void helper(    set<vector<int>>&       svi     ,
                        vector<int>&            cur     ,
                        vector<int>&            nums    ,
                        vector<int>&            visited
                    )
        {
            if(cur.size() == nums.size())
            {
                svi.insert(cur);
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
                    helper(svi,cur,nums,visited);       // explore
                    visited[i]  =   0;                  // unchoose
                    cur.pop_back();
                }
                
            }
            
        }
    
    public:

        vector<vector<int>> permuteUnique(vector<int>& nums)
        {
            vector<vector<int>> vvi;
            set<vector<int>>    svi;
            vector<int>         cur;
            vector<int>         visited(nums.size(),0);
            
            if(nums.size() < 1)
            {
                return vvi;
            }
            helper(svi, cur, nums , visited);
            
            set<vector<int>> ::iterator iter = svi.begin();
            while(iter != svi.end())
            {
                vvi.push_back(*iter);
                iter++;
            }

            return vvi;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :208 ms, 在所有 cpp 提交中击败了11.33% 的用户
内存消耗 :10.7 MB, 在所有 cpp 提交中击败了53.01%的用户
*/

