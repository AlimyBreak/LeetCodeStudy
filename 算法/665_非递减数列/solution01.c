
bool checkPossibility(  int*    nums        ,
                        int     numsSize
                     )
{
    bool ret_val        = true  ;
    int  i              = 0     ;
    int  invalid_count  = 0     ;
    int  temp_index     = -1    ;
    
    if(numsSize<=2)
    {
        return ret_val;        
    }
    else
    {
        for(i=1;i<numsSize;i++)
        {
            if(nums[i]<nums[i-1])
            {
                temp_index = i;
                invalid_count++;
            }
        }
        
        
        switch(invalid_count)
        {
            case 0:
                ret_val = true;
            break;
            
            case 1:
                if(   (temp_index==1) 
                   || (temp_index==numsSize-1)
                )
                {
                    ret_val = true;
                }
                else
                {
                    if(  (nums[temp_index+1]>=nums[temp_index-1])
                       ||(nums[temp_index]>=nums[temp_index-2])
                    )
                    {
                        ret_val = true;
                    }
                    else
                    {
                        ret_val = false;
                    }
                    
                }
            break;
            default:
                ret_val = false;
            break;
        }
    }
    
    return ret_val;
    
}

/*
执行结果：
通过
显示详情
执行用时 :36 ms, 在所有 C 提交中击败了91.35% 的用户
内存消耗 :8.2 MB, 在所有 C 提交中击败了70.59%的用户
*/