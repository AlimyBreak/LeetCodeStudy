int searchInsert(int* nums, int numsSize, int target)
{
    int i = 0;
    
    if(target <= nums[0])
    {
        return 0;
    }
    
    if(target > nums[numsSize-1])
    {
        return numsSize;
    }
    
    for(i=1;i<numsSize;i++)
    {
        if(target<=nums[i])
        {
            return i ;
        }
    }
    
    return -1; /* Anti warnning ,若在这里返回,那输入一定有问题.*/
}

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C 提交中击败了89.76% 的用户
内存消耗 :7.1 MB, 在所有 C 提交中击败了79.28%的用户
*/
