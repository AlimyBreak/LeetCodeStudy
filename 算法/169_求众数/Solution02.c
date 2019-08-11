


int majorityElement(int* nums, int numsSize)
{
    
    int i       =   0       ;
    int j       =   0       ;
    int ret_val =   rand()  ;
    int vote    =   0       ;
    
    for(i = numsSize-1 ; i >=0  ; i--)
    {
        if(ret_val == nums[i])
        {
            continue;
        }
        ret_val = nums[i];
        vote = 0;
        for(j=i;j>=0;j--)
        {
            if(nums[j]==ret_val)
            {
                vote++;
            }
            else
            {
                vote--;
            }
        }
        if(vote>=0)
        {
            break;
        }   
    }
    return ret_val;
}


/*
执行结果：
通过
显示详情
执行用时 :28 ms, 在所有 C 提交中击败了85.92% 的用户
内存消耗 :8.9 MB, 在所有 C 提交中击败了52.54%的用户
*/