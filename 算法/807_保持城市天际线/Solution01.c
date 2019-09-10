int maxIncreaseKeepingSkyline(  int**   grid        ,
                                int     gridSize    ,
                                int*    gridColSize
                             )
{
    int     i           =   0;
    int     j           =   0;
    int     ret_val     =   0;
    int*    rows_max    =   (int*)malloc(gridSize*sizeof(int));
    int*    cols_max    =   (int*)malloc((*gridColSize)*sizeof(int));
    
    
    /* 求出行最大值   */
    for(i = 0 ; i < gridSize ; i++)
    {
        rows_max[i] = grid[i][0];
        for(j = 1; j < *gridColSize ; j++)
        {
            if(grid[i][j] > rows_max[i])
            {
                rows_max[i] = grid[i][j];
            }
        }
    }
    
    /* 求出列最大值   */
    for(i = 0 ; i < *gridColSize ; i++)
    {
        cols_max[i] = grid[0][i];
        for(j = 1 ; j < gridSize ; j++)
        {
            if(grid[j][i] > cols_max[i])
            {
                cols_max[i] = grid[j][i];
            }
        }
    }
    
    for(i = 0 ; i < gridSize ; i++) /* 遍历行*/
    {
        for(j = 0 ; j < *gridColSize ; j++) /* 遍历列*/
        {
            //ret_val += __min(rows_max[i],cols_max[j]) - grid[i][j];
            ret_val +=  (rows_max[i]>cols_max[j] ? cols_max[j] : rows_max[i]) - grid[i][j];
        }
    }
    
    free(rows_max);
    free(cols_max);
    
    return ret_val;
}

/*
执行结果：
通过
显示详情
执行用时 :12 ms, 在所有 C 提交中击败了88.89% 的用户
内存消耗 :7.4 MB, 在所有 C 提交中击败了100.00%的用户
*/