/*
在一个给定的数组nums中，总是存在一个最大元素 。
查找数组中的最大元素是否至少是数组中每个其他数字的两倍。
如果是，则返回最大元素的索引，否则返回-1。
示例 1
输入 nums = [3, 6, 1, 0]
输出 1
解释 6是最大的整数, 对于数组中的其他整数,
6大于数组中其他元素的两倍。6的索引是1, 所以我们返回1.

示例 2
输入 nums = [1, 2, 3, 4]
输出 -1
解释 4没有超过3的两倍大, 所以我们返回 -1.
提示
    nums 的长度范围在[1, 50].
    每个 nums[i] 的整数范围在 [0, 99].
*/

/*方法1:常规方法,两次循环找最大第二大数对应的index,然后比较.*/
int dominantIndex(int* nums, int numsSize)
{
    int ret_index       =   -1  ;
    int firstMaxIndex   =   0   ;
    int secondMaxIndex  =   0   ;
    int i               =   0   ;
    
    do
    {    
        if(numsSize == 1)
        {
            ret_index = 0;
            break;
        }
        for(i = 0; i < numsSize ; i++)
        {
            if(nums[i]>nums[firstMaxIndex])
            {
                firstMaxIndex = i;
            }
        }
        
        if(firstMaxIndex==0)
        {
            secondMaxIndex = 1;
        }
        
        for(i=0;i<numsSize;i++)
        {
            if(i==firstMaxIndex)
            {
                continue;
            }
            
            if(nums[i]>nums[secondMaxIndex])
            {
                secondMaxIndex = i;
            }
        }
        if(nums[firstMaxIndex] >=2*nums[secondMaxIndex])
        {
            ret_index = firstMaxIndex;
        }
    }while(0);


    return ret_index;
}

/*
执行结果：通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了92.81%的用户
内存消耗 :6.9 MB, 在所有 C 提交中击败了79.49%的用户
*/