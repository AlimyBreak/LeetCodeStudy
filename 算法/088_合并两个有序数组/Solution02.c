
void merge( int*    nums1       ,
            int     nums1Size   ,
            int     m           ,
            int*    nums2       ,
            int     nums2Size   ,
            int     n
            )
{
    int  num_count  =   m+n-1   ;
    int  i          =   m-1     ;
    int  j          =   n-1     ;
    
    while(1)
    {
        if(  (i>=0)
           &&(j>=0)
        )
        {   
            if(nums1[i]>nums2[j])
            {
                nums1[num_count] = nums1[i];
                i--;
            }
            else
            {
                nums1[num_count] = nums2[j];
                j--;
            }
            num_count--;
        }
        else if(i >=0)
        {
            if(num_count!=i)
            {
                nums1[num_count] = nums1[i];
            }
            i--;
            num_count--;
        }
        else if(j >= 0)
        {
            nums1[num_count] = nums2[j];
            j--;
            num_count--;
        }
        else
        {
            break;
        }
    }

    return ;    
}

/*
执行结果：
通过
显示详情
执行用时 :16 ms, 在所有 C 提交中击败了8.52% 的用户
内存消耗 :7.3 MB, 在所有 C 提交中击败了75.70%的用户
*/