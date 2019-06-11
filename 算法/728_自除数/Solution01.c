/*
自除数 是指可以被它包含的每一位数除尽的数。
例如，128 是一个自除数，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
还有，自除数不允许包含 0 。
给定上边界和下边界数字，输出一个列表，列表的元素是边界（含边界）内所有的自除数。
示例 1：
输入： 
上边界left = 1, 下边界right = 22
输出： [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
注意：
    每个输入参数的边界满足 1 <= left <= right <= 10000。
*/

bool checkSelfDiv( int data )
{
    bool    ret_val     =   true;
    int     temp        =   data;
    int     leaves      =   0;
    
    while(temp!=0)
    {
        leaves = temp % 10;
        if(leaves!=0)
        {
            if(data % leaves != 0 )
            {
                ret_val = false;
                break;
            }
        }
        else
        {
            ret_val = false;
            break;
        }
        temp /= 10;
    }
    return ret_val;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize)
{
    int*    ret_val     =   (int*)malloc(sizeof(int)*(right-left+1))    ;
    int     validsize   =   0                                           ;
    int     i           =   0                                           ;
    if(ret_val == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    for(i = left ; i <= right ; i++)
    {
        if(checkSelfDiv(i))
        {
            ret_val[validsize] = i;
            validsize++;
        }
    }
    *returnSize = validsize;
    return ret_val;
}


/*
最近提交结果：通过
显示详情 
执行用时 :0 ms, 在所有C提交中击败了100.00%的用户
内存消耗 :7.7 MB, 在所有C提交中击败了6.98%的用户
31 / 31 个通过测试用例
状态：通过
执行用时：0 ms
提交时间：3 分钟之前
*/
