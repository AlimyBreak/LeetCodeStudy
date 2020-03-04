class Solution
{
    private:

        int minute_event(   vector<vector<int>>&        grid            ,
                            vector<vector<int>>&        vistied         ,
                            int                         r               ,
                            int                         c               ,
                            int                         cur_fresh_num
    )
    {

        int i = 0;
        int j = 0;

        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (grid[i][j] == 0)
                {
                    continue;
                }
                else if (grid[i][j] == 1)
                {
                    continue;
                }
                else
                {
                    if (vistied[i][j] == 0 || vistied[i][j] == 1)
                    {
                        //上
                        if (i - 1 >= 0 && grid[i - 1][j] == 1)
                        {
                            grid[i - 1][j] = 2;
                            vistied[i - 1][j] = 2;
                            cur_fresh_num--;
                        }

                        //下
                        if (i + 1 < r && grid[i + 1][j] == 1)
                        {
                            grid[i + 1][j] = 2;
                            vistied[i + 1][j] = 2;
                            cur_fresh_num--;
                        }

                        //左
                        if (j - 1 >= 0 && grid[i][j - 1] == 1)
                        {
                            grid[i][j - 1] = 2;
                            vistied[i][j - 1] = 2;
                            cur_fresh_num--;
                        }
                        //右

                        if (j + 1 < c && grid[i][j + 1] == 1)
                        {
                            grid[i][j + 1] = 2;
                            vistied[i][j + 1] = 2;
                            cur_fresh_num--;
                        }

                        vistied[i][j] = 1;

                    }
                    else if (vistied[i][j] == 2)
                    {
                        vistied[i][j] = 1;
                    }
                }
            }
        }

        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (vistied[i][j] == 2)
                {
                    vistied[i][j] = 1;
                }
            }

        }
        return cur_fresh_num;
    }

    public:
        int orangesRotting(vector<vector<int>>& grid)
        {
            int r               = grid.size()       ;
            int c               = grid[0].size()    ;
            int cur_rotten_num  = 0                 ;
            int cur_fresh_num   = 0                 ;
            int new_fresh_num   = 0                 ;
            int minutes         = 0                 ;
            int i               = 0                 ;
            int j               = 0                 ;
            
            vector<vector<int>>  vistied(r, vector<int>(c, 0));

            for (i = 0; i < r; i++)
            {
                for (j = 0; j < c; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        cur_fresh_num++;
                    }
                    else if (grid[i][j] == 2)
                    {
                        cur_rotten_num++;
                    }
                }
            }
            
            if (cur_rotten_num != 0)
            {

                while (1)
                {
                    new_fresh_num = minute_event(grid, vistied, r, c, cur_fresh_num);
                    if (new_fresh_num == cur_fresh_num)
                    {
                        break;
                    }
                    cur_fresh_num = new_fresh_num;
                    minutes++;
                }
            }
            
            if (cur_fresh_num == 0)
            {
                return minutes;
            }
            else
            {
                return -1;
            }
        }
};        


/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C++ 提交中击败了76.60% 的用户
内存消耗 :15.2 MB, 在所有 C++ 提交中击败了5.40%的用户
*/          