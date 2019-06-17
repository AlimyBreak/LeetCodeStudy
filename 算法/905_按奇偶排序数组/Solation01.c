/*
给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。
你可以返回满足此条件的任何数组作为答案。
示例：
输入：[3,1,2,4]
输出：[2,4,3,1]
输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
提示：
    1 <= A.length <= 5000
    0 <= A[i] <= 5000
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 方法1:遍历原数组，逐一从头尾插入
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    
    int* ret_val        = (int*)calloc(sizeof(int)*ASize);
    int* pointer_head   = NULL;
    int* pointer_tail   = NULL;
    int  i              = 0;
    
    if(ret_val==NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    pointer_head = ret_val;
    pointer_tail = &ret_val[ASize-1];

    for(i=0;i < ASize ; i ++)
    {
        if(A[i] % 2 == 0)
        {
            *pointer_head = A[i];
            pointer_head ++ ;
            
        }
        else
        {
            *pointer_tail = A[i];
            pointer_tail -- ;
        }
    }
    *returnSize = ASize;
    return ret_val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 方法2:可以不遍历，直接从头尾开始判断，遇到不合适的就交换.
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    
    int* ret_val        = (int*)malloc(sizeof(int)*ASize);
    int* pointer_head   = NULL;
    int* pointer_tail   = NULL;
    int  tmp            = 0;
    
    memcpy(ret_val,A,sizeof(int)*ASize);
    if(ret_val==NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    
    pointer_head = ret_val;
    pointer_tail = &ret_val[ASize-1];
    while(pointer_head < pointer_tail)
    {
        if((*pointer_head % 2 == 1)&&(*pointer_tail % 2 == 0))
        {
            tmp           = *pointer_tail;
            *pointer_tail = *pointer_head;
            *pointer_head = tmp;
        }
        
        if(*pointer_head % 2 == 0)
        {
            pointer_head ++;
        }
        
        if(*pointer_tail % 2 == 1)
        {
            pointer_tail --;
        }   
    }
    
    *returnSize = ASize;
    return ret_val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 × 方法3：使用位运算做奇偶判断，二进制整数的奇偶性完全由第0位就可以确定。
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    
    int* ret_val        = (int*)malloc(ASize*sizeof(int)) ;
    int* pointer_head   = NULL;
    int* pointer_tail   = NULL;
    int  tmp            = 0;
    
    
    memcpy(ret_val,A,ASize*sizeof(int));
    pointer_head = ret_val;
    pointer_tail = &ret_val[ASize-1];
    while(pointer_head < pointer_tail)
    {
        if(  ( ((*pointer_head) & 1) == 1  )
           &&( ((*pointer_tail) & 1) == 0  )
        )
        {
            tmp           = *pointer_tail;
            *pointer_tail = *pointer_head;
            *pointer_head = tmp;
        }
        
        if( ((*pointer_head) & 1) == 0)
        {
            pointer_head ++;
        }
        
        if( ((*pointer_tail) & 1) == 1)
        {
            pointer_tail --;
        }   
    }
    *returnSize = ASize;
    return ret_val;
}


/*
方案1:
执行用时 :64 ms, 在所有C提交中击败了25.23%的用户
内存消耗 :10.4 MB, 在所有C提交中击败了77.94%的用户
*/

/*
方案2:
执行用时 :52 ms, 在所有C提交中击败了30.37%的用户
内存消耗 :10.2 MB, 在所有C提交中击败了84.56%的用户
*/

/*
方案3:
执行用时 :40 ms, 在所有C提交中击败了92.52%的用户
内存消耗 :10.2 MB, 在所有C提交中击败了83.82%的用户
*/