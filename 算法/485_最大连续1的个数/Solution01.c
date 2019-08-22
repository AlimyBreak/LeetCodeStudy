
int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int i           = 0;
    int ind_front   = 0;
    int ind_tail    = 0;
    int ret_val     = 0;

    for(i=0;i<numsSize;i++)
    {
        if(nums[ind_front]==0)
        {
            ind_front++;
            ind_tail++;
        }
        else
        {
            if(nums[ind_tail]==1)
            {
                ind_tail++;
            }
            else
            {
                ret_val = (ret_val>=(ind_tail-ind_front)) ?  ret_val : (ind_tail-ind_front);
                ind_tail++;
                ind_front=ind_tail;
            }
        }
    }
    ret_val = (ret_val>=(ind_tail-ind_front)) ?  ret_val : (ind_tail-ind_front);
    return ret_val;
}

/*
执行结果：
通过
显示详情
执行用时 :56 ms, 在所有 C 提交中击败了95.08% 的用户
内存消耗 :8.7 MB, 在所有 C 提交中击败了48.76%的用户
*/