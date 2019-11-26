class Solution
{
    
    private:
        void helper(    int& pathnum,
                        vector<vector<int>>&    grid            ,
                        int                     cur_row         ,
                        int                     cur_col         ,
                        int                     cur_num_zero    ,
                        int                     num_zeros       ,
                        vector<vector<int>>&    visited
        )
        {

            if(     cur_row < 0
                ||  cur_row >= grid.size()
                ||  cur_col < 0
                ||  cur_col >= grid[0].size()
            )
            {
                /* 范围越界 */
                return;
            }
        
            if(grid[cur_row][cur_col] == 2)
            {
                if (cur_num_zero == num_zeros)
                {
                    pathnum++;
                }
                else
                {
                    return;
                }
            }

            /*障碍物无法通过*/
            if(grid[cur_row][cur_col] == -1)
            {
                return;
            }

            /*回到起始位置了*/
            if(    grid[cur_row][cur_col]   ==  1 
                && cur_num_zero             !=  0
            )
            {
                return;
            }


            // grid[cur_row][cur_col] == 0 或者 grid[cur_row][cur_col] == 1
            if (visited[cur_row][cur_col] == 1)
            {
                return;
            }
            else
            {
                visited[cur_row][cur_col] = 1;
                if(grid[cur_row][cur_col] == 0)    /**/
                {
                    cur_num_zero++;
                }
                /*上*/
                helper(pathnum, grid, cur_row - 1, cur_col, cur_num_zero , num_zeros, visited);
                /*下*/
                helper(pathnum, grid, cur_row + 1, cur_col, cur_num_zero , num_zeros, visited);
                /*左*/
                helper(pathnum, grid, cur_row, cur_col - 1, cur_num_zero , num_zeros, visited);
                /*右*/
                helper(pathnum, grid, cur_row, cur_col + 1, cur_num_zero , num_zeros, visited);
                visited[cur_row][cur_col] = 0;
            }
        }

    public:
        int uniquePathsIII(vector<vector<int>>& grid)
        {
            int start_row   =   -1              ;
            int start_col   =   -1              ;
            int num_zeros   =   0               ;

            int r           =   grid.size()     ;
            int c           =   grid[0].size()  ;

            int pathnum     =   0               ;
            
            vector<vector<int>>    visited = vector<vector<int>>(r, vector<int>(c, 0));

            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (grid[i][j] == 0)
                    {
                        num_zeros++;
                    }
                    else if (grid[i][j] == 1)
                    {
                        start_row = i;
                        start_col = j;
                    }
                    // 貌似没用到
                    // int end_row = -1;
                    // int end_col = -1;
                    // else if (grid[i][j] == 2)
                    //{
                    //    end_row = i;    
                    //    end_col = j;
                    //}
                }
            }
            helper(pathnum, grid, start_row, start_col, 0, num_zeros, visited);
            return pathnum;
        }
};



/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 cpp 提交中击败了89.61% 的用户
内存消耗 :8.4 MB, 在所有 cpp 提交中击败了94.12%的用户
*/