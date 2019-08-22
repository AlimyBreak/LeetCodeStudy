int searchInsert(int* nums, int numsSize, int target)
{
    int i           =   0;
    int ret_val     =   0;
    int left        =   0;
    int right       =   numsSize - 1;
    int mid         =   0;
    int temp1       =   0;
    
    if(target <= nums[0])
    {
        return 0;
    }
    if(target > nums[numsSize-1])
    {
        return numsSize;
    }

    while(left<=right)
    {
        mid     = left + (right-left)/2; /*防止加法溢出*/
        temp1   = nums[mid];
        if( temp1 > target)
        {
            right = mid - 1;
            continue;
        }
        else if(temp1==target)
        {
            return mid;
        }
        else
        {
            if(nums[mid+1]>=target)
            {
                return mid + 1;
            }
            else
            {
                left = mid + 1;
            }    
        }
    }
    return -1;/* Anti warnning ,若在这里返回,那输入一定有问题.*/
}

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了99.87% 的用户
内存消耗 :7.3 MB, 在所有 C 提交中击败了66.60%的用户
*/
