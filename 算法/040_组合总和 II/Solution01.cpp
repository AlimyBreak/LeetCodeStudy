class Solution
{
    
    private:
    
        void helper(    vector<vector<int>>&        vvi             ,
                        vector<int>&                candidates      ,
                        int                         target          ,
                        int                         cur_sum         ,
                        vector<int>&                cur_vi          ,
                        int                         idx             ,
                        vector<int>&                visited         
                   )
        {
            if(cur_sum == target)
            {
                vvi.push_back(cur_vi);
                return ;
            }
            
            
            
            for(int i = idx ; i < candidates.size() ; i++)
            {
                if(cur_sum+candidates[i] > target)
                {
                    continue;
                }
                
                if(i>0 && candidates[i] == candidates[i-1] && !visited[i-1])
                {
                    continue;
                }

                cur_vi.push_back(candidates[i]);
                visited[i] = 1;
                helper(vvi,candidates,target,cur_sum+candidates[i],cur_vi,i+1,visited);
                visited[i] = 0; 
                cur_vi.pop_back();
            }

        }
    
    
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
        {
            vector<vector<int>> vvi;
            
            if(candidates.size() < 1)
            {
                return vvi;
            }
            vector<int> cur_vi;
            vector<int> visited(candidates.size(),0);
            sort(candidates.begin(),candidates.end());
            helper(vvi,candidates,target,0,cur_vi,0,visited);
            return vvi;

        
        }
};


/*
执行结果：
通过
显示详情
执行用时 :12 ms, 在所有 cpp 提交中击败了79.44% 的用户
内存消耗 :9.1 MB, 在所有 cpp 提交中击败了90.14%的用户
*/