

/*
给定由若干 0 和 1 组成的数组 A。我们定义 N_i：从 A[0] 到 A[i] 的第 i 个子数组被解释为一个二进制数（从最高有效位到最低有效位）。

返回布尔值列表 answer，只有当 N_i 可以被 5 整除时，答案 answer[i] 为 true，否则为 false。
示例 1：

输入：[0,1,1]
输出：[true,false,false]
解释：
输入数字为 0, 01, 011；也就是十进制中的 0, 1, 3 。只有第一个数可以被 5 整除，因此 answer[0] 为真。
示例 2：

输入：[1,1,1]
输出：[false,false,false]
示例 3：

输入：[0,1,1,1,1,1]
输出：[true,false,false,false,true,false]
示例 4：

输入：[1,1,1,0,1]
输出：[false,false,false,false,false]

提示：
1 <= A.length <= 30000
A[i] 为 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-prefix-divisible-by-5
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/




/*
* 由于1 <= A.length <= 30000 显然直接做二进制位移很容易溢出,不能直接做移位操作或乘2操作，必然溢出。
* 对于取余操作有如下恒等式
* (A*2+B)%5 == ( (x+5*y)*2 + B) % 5 == (x*2+B)%5 == ((A%5)*2 + B)%5
* 我们可以提前处理，防止计算溢出。
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool* prefixesDivBy5(int* A, int ASize, int* returnSize)
{
    bool*        ret_val   = NULL    ;
    int          i         = 0       ;
    int          j         = 0       ;
    unsigned int temp_sum  = 0       ;
        
    do
    {
        if(  ( A          ==    NULL    )
           ||( ASize      <=    0       )
           ||( returnSize ==    NULL    )
        )
        {
            *returnSize = 0;
            break;
        }
        ret_val = (bool*)malloc(sizeof(bool)*ASize);
        if(ret_val == NULL)
        {
            break; 
        }
        else
        {
            for(i=0;i<ASize;i++)
            {
               ret_val[i] = false; 
            }
            for(i=0;i<ASize;i++)
            {
                temp_sum = (temp_sum << 1)+A[i]; /*这里需要注意优先级*/
                if(temp_sum%5==0)
                {
                    ret_val[i] = true;
                }
                temp_sum = temp_sum%5;                
            }
            
        }
        *returnSize = ASize;
    }while(0);
    return ret_val;
}

/*
执行结果：通过
显示详情
执行用时 :36 ms, 在所有 C 提交中击败了92.59%的用户
内存消耗 :11.5 MB, 在所有 C 提交中击败了6.52%的用户
https://www.cnblogs.com/alimy/p/11169815.html
*/



/*使用数组优化%操作*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* A, int ASize, int* returnSize)
{
    bool*               ret_val   = NULL    ;
    int                 i         = 0       ;
    unsigned int        temp_sum  = 0    ;
    const unsigned int  arr[]     = {0,1,2,3,4,0,1,2,3,4,0};
    do
    {
        if(  (A==NULL)
           ||(ASize<=0)
           ||(returnSize==NULL)
        )
        {
            *returnSize = 0;
            break;
        }
        ret_val = (bool*)malloc(sizeof(bool)*ASize);
        if(ret_val == NULL)
        {
            break; 
        }
        else
        {
            for(i=0;i<ASize;i++)
            {
               ret_val[i] = false; 
            }
            
            for(i=0;i<ASize;i++)
            {
                temp_sum = arr[((temp_sum << 1)+A[i])]; /*这里注意优先级*/
                if(temp_sum==0)
                {
                    ret_val[i] = true;
                }               
            }   
        }
        *returnSize = ASize;
        
    
    }while(0);
    return ret_val;
}



/*
执行结果：通过
显示详情
执行用时 :28 ms, 在所有 C 提交中击败了98.77%的用户
内存消耗 :11.7 MB, 在所有 C 提交中击败了6.52%的用户
*/