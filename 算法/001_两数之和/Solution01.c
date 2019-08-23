/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(    int*        nums        ,
                int         numsSize    ,
                int         target      ,
                int*        returnSize
            )
{
    int     i       =   0                               ;
    int     j       =   0                               ;
    int*    index   =   (int*)malloc(2*sizeof(int))     ;
    int     valid   =   0                               ;
    
    
    for(i = 0; i < numsSize ;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j] == target)
            {
                index[0] = i;
                index[1] = j;
                valid = 1;
            }
        }
        if(valid==1)
        {
            break;
        }
    }

    if(valid == 1)
    {
        *returnSize = 2;
    }
    else
    {
        *returnSize = 0;
        free(index);
        index = NULL;
    }
    return index;
}

/*
执行结果：
通过
显示详情
执行用时 :268 ms, 在所有 C 提交中击败了33.00% 的用户
内存消耗 :7.6 MB, 在所有 C 提交中击败了45.87%的用户
*/