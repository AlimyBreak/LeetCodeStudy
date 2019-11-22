class Solution
{
    
    private:
        
        void helper (   vector<vector<int>>&    vvi             ,
                        vector<int>&            candidates      ,
                        int                     cur_sum         ,
                        vector<int>&            cur_vi          ,
                        int                     idx             ,
                        int                     target          
                    )
        {
            
            if(cur_sum == target)
            {
                vvi.push_back(cur_vi);
                return;
            }
            
            /*题目已知全是正整数,不必考虑负数的情况*/
            
            for(int i = idx ; i < candidates.size() ; i++)
            {
                if(cur_sum+candidates[i] > target)
                {
                    continue;
                }
                
                cur_vi.push_back(candidates[i]);
                helper(vvi,candidates,cur_sum+candidates[i],cur_vi,i,target);
                cur_vi.pop_back();
            }
        }
    
    
    
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target)
        {
            vector<vector<int>> vvi;
            
            if(candidates.size() < 1)
            {
                return vvi;
            }
            
            vector<int> vi;
            
            sort(candidates.begin(),candidates.end());
            helper(vvi,candidates,0,vi,0,target);

            return vvi;
            
            
        }
};


/*
执行结果：
通过
显示详情
执行用时 :16 ms, 在所有 cpp 提交中击败了85.61% 的用户
内存消耗 :9.3 MB, 在所有 cpp 提交中击败了93.78%的用户
*/