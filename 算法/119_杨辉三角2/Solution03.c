/* 层次迭代法*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(    int     rowIndex    ,
                int*    returnSize
           )
{
    int*            ret_val = NULL  ;
    int             i       = 0     ;
    int             j       = 0     ;
    unsigned long   temp    = 1     ;
    
    *returnSize = ++rowIndex;
    ret_val     = (int*)malloc(sizeof(int)*(rowIndex));
    memset(ret_val,0,sizeof(int)*(rowIndex));
    ret_val[rowIndex-1]  = temp ;
    ret_val[0] = 1;
    for(i=1;i<rowIndex;i++)
    {
        for(j=rowIndex-2;j>0;j--)
        {
            ret_val[j] = ret_val[j-1] + ret_val[j];
        }
    }
    return ret_val;
}

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了78.57% 的用户
内存消耗 :7.1 MB, 在所有 C 提交中击败了6.10%的用户
*/

