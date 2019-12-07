class Solution
{
    
    private:
    
        void helper(    int&                    max_gold    ,
                        int                     cur_gold    ,
                        vector<vector<int>>&    grid        ,
                        vector<vector<bool>>&   vvb         ,
                        int                     cur_i       ,
                        int                     cur_j       ,
                        int                     R           ,
                        int                     C
                   )
        {
            if(     (   cur_i < 0                      )
                ||  (   cur_i >= R                     )
                ||  (   cur_j < 0                      )
                ||  (   cur_j >= C                     )
                ||  (   grid[cur_i][cur_j] == 0        )
                ||  (   vvb[cur_i][cur_j] == true      )
            )
            {
                if(cur_gold > max_gold)
                {
                    max_gold = cur_gold;
                }
                
                return;
            }
            vvb[cur_i][cur_j] = true;
            cur_gold += grid[cur_i][cur_j];
            helper(max_gold,cur_gold,grid,vvb,cur_i+1,cur_j,R,C);
            helper(max_gold,cur_gold,grid,vvb,cur_i-1,cur_j,R,C);
            helper(max_gold,cur_gold,grid,vvb,cur_i,cur_j+1,R,C);
            helper(max_gold,cur_gold,grid,vvb,cur_i,cur_j-1,R,C);
            vvb[cur_i][cur_j] = false;
        }
        
    
    
    public:
        int getMaximumGold(vector<vector<int>>& grid)
        {
            
            if(grid.size() < 1)
            {
                return 0;
            }
            
            int max_gold = 0;
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<bool>> vvb = vector<vector<bool>>(m,vector<bool>(n,false));
            for(int i = 0 ; i < m ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    helper(max_gold,0,grid,vvb,i,j,m,n);
                }
            }
            return max_gold;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :132 ms, 在所有 cpp 提交中击败了20.06% 的用户
内存消耗 :8.9 MB, 在所有 cpp 提交中击败了100.00%的用户
*/