
void merge( int*    nums1       ,
            int     nums1Size   ,
            int     m           ,
            int*    nums2       ,
            int     nums2Size   ,
            int     n
            )
{
    int* temp       =   (int*)malloc(nums1Size*sizeof(int)) ;   /*申请辅助空间用于归并*/
    int  num_count  =   0                                   ;
    int  i          =   0                                   ;
    int  j          =   0                                   ;
    
    while(1)
    {
        if((i<m)&&(j<n))
        {   
            if(nums1[i]<nums2[j])
            {
                temp[num_count] = nums1[i];
                i++;
            }
            else
            {
                temp[num_count] = nums2[j];
                j++;
            }
            num_count++;
        }
        else if(i < m)
        {
            temp[num_count] = nums1[i];
            i++;
            num_count++;
        }
        else if(j < n)
        {
            temp[num_count] = nums2[j];
            j++;
            num_count++;
        }
        else
        {
            break;
        }
    }
    
    memcpy(nums1,temp,(m+n)*sizeof(int));
    free(temp);/*释放空间*/
    return ;
    
}


/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C 提交中击败了70.66% 的用户
内存消耗 :7.3 MB, 在所有 C 提交中击败了71.98%的用户
*/