
/*
给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。

对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。

你可以返回任何满足上述条件的数组作为答案。
示例：
输入：[4,2,5,7]
输出：[4,5,2,7]
解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
提示：
    2 <= A.length <= 20000
    A.length % 2 == 0
    0 <= A[i] <= 1000
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize)
{
    int* ret_val = NULL;
    int  i       = 0;
    int  j       = 0;
    int  k       = 0;
    int  temp    = 0;
    
    ret_val =  (int*)malloc(ASize*sizeof(int));
    if(ret_val == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    
    memset(ret_val,0,sizeof(ASize*sizeof(int)));
    
    for( i = 0 ; i < ASize ; i++)
    {
        temp = A[i];
        if(temp % 2 == 0)
        {
            ret_val[2*j] = temp;
            j++;
        }
        else
        {
            ret_val[2*k+1] = temp;
            k++;
        }
    }
    
    *returnSize = j+k;
    
    return ret_val;
}

/*
执行用时 : 100 ms, 在Sort Array By Parity II的C提交中击败了53.77% 的用户
内存消耗 : 14.7 MB, 在Sort Array By Parity II的C提交中击败了54.00% 的用户
61 / 61 个通过测试用例
状态：通过
执行用时：100 ms
提交时间：3 分钟之前
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize)
{
    int* ret_val = NULL;
    int  i       = 0;
    int  j       = 0;
    int  k       = 1;
    int  temp    = 0;
    
    ret_val =  (int*)malloc(ASize*sizeof(int));
    if(ret_val == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    
    memset(ret_val,0,sizeof(ASize*sizeof(int)));
    
    for( i = 0 ; i < ASize ; i++)
    {
        temp = A[i];
        if(temp % 2 == 0)
        {
            ret_val[j] = temp;
            j += 2;
        }
        else
        {
            ret_val[k] = temp;
            k += 2;
        }
    }
    
    *returnSize = ASize;
    
    return ret_val;
}

/*
执行用时 : 88 ms, 在Sort Array By Parity II的C提交中击败了99.06% 的用户
内存消耗 : 14.6 MB, 在Sort Array By Parity II的C提交中击败了58.00% 的用户
61 / 61 个通过测试用例
状态：通过
执行用时：88 ms
提交时间：0 分钟之前
*/
