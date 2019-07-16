
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(   int* digits,int digitsSize, int* returnSize)
{
    
    int*    ret_val    =    NULL   ;
    int*    ret_val2   =    NULL   ;
    int     carry      =    1      ;
    int     temp       =    0      ;
    int     i          =    0      ;
    
    ret_val = (int*)malloc(digitsSize*sizeof(int));
    carry = 1;
    for(i = digitsSize-1;i>=0;i--)
    {
        temp        =   (digits[i] + carry )    ;
        ret_val[i]  =   temp % 10               ;
        carry       =   temp / 10               ;
    }
    if(carry == 1)
    {
        ret_val2        =  (int*)malloc((digitsSize+1)*sizeof(int));
        ret_val2[0]     = carry;
        memcpy(&ret_val2[1],ret_val,digitsSize*sizeof(int));
        free(ret_val);
        ret_val = NULL;
        *returnSize = digitsSize + 1;
        return ret_val2;   
    }
    else
    {
        *returnSize = digitsSize;
        return ret_val;
    }
}

/*
执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 C 提交中击败了100.00% 的用户
内存消耗 :7.3 MB, 在所有 C 提交中击败了5.51%的用户
*/