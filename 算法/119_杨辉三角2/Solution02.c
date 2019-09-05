/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(    int     rowIndex    ,
                int*    returnSize
           )
{
    int*            ret_val = NULL  ;
    unsigned long   temp    = 1     ;
    int             i       = 0     ;
    
    *returnSize = rowIndex+1;
    ret_val     = (int*)malloc(sizeof(int)*(rowIndex+1));
    ret_val[0]  = 1 ;
    for(i=1;i<=rowIndex;i++)
    {
        temp = temp *(rowIndex-i+1);
        temp = temp / i ;
        ret_val[i] = temp;
    }
    return ret_val;
}

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C 提交中击败了25.00% 的用户
内存消耗 :7.1 MB, 在所有 C 提交中击败了6.10%的用户
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(    int     rowIndex    ,
                int*    returnSize
           )
{
    int*            ret_val = NULL  ;
    int             i       = 0     ;
    unsigned long   temp    = 1     ;
    
    *returnSize = ++rowIndex;
    ret_val     = (int*)malloc(sizeof(int)*(rowIndex));
    ret_val[0]  = temp ;
    for(i=1;i<rowIndex;i++)
    {
        temp *= (rowIndex-i);
        temp /= i;
        ret_val[i] = temp;
    }
    return ret_val;
}

/*
执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 C 提交中击败了100.00% 的用户
内存消耗 :7 MB, 在所有 C 提交中击败了7.32%的用户
*/

