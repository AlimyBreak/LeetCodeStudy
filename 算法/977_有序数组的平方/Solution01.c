/*
给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

示例 1：

输入：[-4,-1,0,3,10]
输出：[0,1,9,16,100]

示例 2：

输入：[-7,-3,2,3,11]
输出：[4,9,9,49,121]

提示：
    1 <= A.length <= 10000
    -10000 <= A[i] <= 10000
    A 已按非递减顺序排序。
*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 方案1: 从小往大填(需要找到正负分界点)
 */
int* sortedSquares(int* A, int ASize, int* returnSize)
{
    int* ret_val            = (int*)malloc(sizeof(int)*ASize);
    int  i                  = 0;
    int  temp               = 0;
    int  temp2              = 0;
    int* pointer_negative   = NULL; /*包括0*/
    int* pointer_positive   = NULL;
    
    do
    {
        if(A[0] >= 0)
        {
            for(i = 0; i < ASize ; i++)
            {
                temp = A[i];
                ret_val[i]  = temp * temp   ;
            }
            break;
        }
        
        if(A[ASize-1] <= 0)
        {
            for(i = ASize - 1; i>=0 ; i--)
            {
                temp = A[i];
                ret_val[ASize - 1-i] = temp * temp;
            }            
            break;
        }
        
        i = 1;
        while(i<ASize)
        {
            if((A[i]>=0) &&(A[i-1] <=0))
            {
                pointer_negative = &A[i-1]  ;
                pointer_positive = &A[i]    ;
                break;
            }
            i++;
        }
        
        i = 0;
        while((pointer_negative >= &A[0]) || (pointer_positive<=&A[ASize-1]))
        {
            if(pointer_negative < &A[0])
            {
                temp = *pointer_positive;
                ret_val[i] = temp * temp;
                i++;
                pointer_positive++;
                continue;
            }
            
            if(pointer_positive>&A[ASize-1])
            {
                temp = *pointer_negative;
                ret_val[i] = temp * temp;
                i++;
                pointer_negative--;
                continue;
            }
            
            
            temp  = *pointer_negative;
            temp2 = *pointer_positive ;
            
            temp  *= temp;
            temp2 *= temp2;
            
            if(temp <= temp2)
            {
                ret_val[i] = temp;
                i++;
                pointer_negative--;
            }
            else
            {
                ret_val[i] = temp2;
                i++;
                pointer_positive++;
            }
        }
        break;
    }while(0);
    
    *returnSize = ASize;
    return ret_val;
}
/*
执行用时 :256 ms, 在所有 C 提交中击败了29.40%的用户
内存消耗 :21.5 MB, 在所有 C 提交中击败了77.71%的用户
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 方案2: 从大往小填,不存在数组越界问题(利用指针索引)
 */
int* sortedSquares(int* A, int ASize, int* returnSize)
{
    int* ret_val = (int*)malloc(sizeof(int)*ASize);
    int* head    = &A[0];
    int* tail    = &A[ASize-1];
    int  i       = ASize-1;
    
    while(i>=0)
    {
        if(abs(*head)>=abs(*tail))
        {
            ret_val[i] = (*head)*(*head);
            head++;
        }
        else
        {
            ret_val[i] = (*tail)*(*tail);
            tail--;
        }
        i--;
    }
    *returnSize = ASize;
    return ret_val;
}
/*
执行用时 :252 ms, 在所有 C 提交中击败了30.71%的用户
内存消耗 :21.4 MB, 在所有 C 提交中击败了80.89%的用户
*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 方案3: 从大往小填,不存在数组越界问题(利用数字索引)
 */
int* sortedSquares(int* A, int ASize, int* returnSize)
{
    int* ret_val = (int*)malloc(sizeof(int)*ASize);
    int  head    = 0;
    int  tail    = ASize-1;
    int  i       = ASize-1;
    
    while(i>=0)
    {
        if(abs(A[head])>=abs(A[tail]))
        {
            ret_val[i] = A[head]*A[head];
            head++;
        }
        else
        {
            ret_val[i] = A[tail]*A[tail];
            tail--;
        }
        i--;
    }
    *returnSize = ASize;
    return ret_val;   
}
/*
执行用时 :160 ms, 在所有 C 提交中击败了69.03%的用户
内存消耗 :21.3 MB, 在所有 C 提交中击败了85.35%的用户
*/

