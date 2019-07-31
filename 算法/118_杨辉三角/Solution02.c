int** generate( int     numRows             ,
                int*    returnSize          ,
                int**   returnColumnSizes
              )
{
    int** ret_val   = NULL;
    int*  ret_size  = NULL;
    int   i         = 0;
    int   j         = 0;
    
    do
    {
        if(numRows<=0)
        {
            *returnSize         =   0       ;
            *returnColumnSizes  =   NULL    ;
            break;
        }
        
        ret_val  = (int**) malloc(sizeof(int*)*numRows);
        ret_size = (int*)  malloc(sizeof(int) *numRows);
        
        for(i = 0;i < numRows ;i++)
        {
            ret_size[i]     = i+1;
            ret_val[i]      = (int*)malloc((i+1)*sizeof(int));
            ret_val[i][0]   = 1;    /*头尾补1*/
            ret_val[i][i]   = 1;
            if(i>1)
            {
                for(j=0;j<i-1;j++)
                {
                    ret_val[i][j+1] = ret_val[i-1][j] + ret_val[i-1][j+1];
                }
            }         
        }
        *returnSize         = numRows   ;
        *returnColumnSizes  = ret_size  ;
    }while(0);
    return ret_val;
}

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了88.46%的用户
内存消耗 :7.3 MB, 在所有 C 提交中击败了5.69%的用户
*/

