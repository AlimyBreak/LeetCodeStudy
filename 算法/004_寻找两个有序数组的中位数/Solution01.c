double findMedianSortedArrays(  int*        nums1       ,
                                int         nums1Size   ,
                                int*        nums2       ,
                                int         nums2Size
                            )
{
    int type        = (nums1Size % 2 + nums2Size % 2) % 2               ;
    int loc1        = (nums1Size + nums2Size)/2 -1                      ; /*这里依然可能会有溢出*/
    int loc2        = loc1+1                                            ;
    int count       = 0                                                 ;
    int i           = 0                                                 ;
    int j           = 0                                                 ;
    double temp0    = 0.0                                               ;
    double temp1    = 0.0                                               ;
    double temp2    = 0.0                                               ;

    if(nums1Size==0 && nums2Size==0)
    {
        return 0.0;
    }
    else if(nums2Size ==0)
    {
        if(nums1Size%2==0)
        {
            return (double)(nums1[nums1Size/2-1]+nums1[nums1Size/2])/2.0;
        }
        else
        {
            return (double)(nums1[nums1Size/2]);
        }
        
    }
    else if (nums1Size ==0)
    {
        if(nums2Size%2==0)
        {
            return (double)(nums2[nums2Size/2-1]+nums2[nums2Size/2])/2.0;
        }
        else
        {
            return (double)(nums2[nums2Size/2]);
        }       
    }
    else
    {
        while (1)
        {
            if(  (i<nums1Size)
               &&(j<nums2Size)
            )
            {
                if(nums1[i]<=nums2[j])
                {
                    temp0 = nums1[i];
                    i++;

                }
                else
                {
                    temp0 = nums2[j];
                    j++;

                }

            }
            else if(i<nums1Size)
            { 
                temp0 = nums1[i];
                i++;

            }
            else if(j<nums2Size)
            {
                temp0 = nums2[j];
                j++;

            }
            else
            {
                break;    
            }

            if(count==loc1)
            {
                temp1 = temp0;
            }
            if(count==loc2)
            {
                temp2 = temp0;
                break;
            }
            count++;
        }
        if(type == 1)
        {
            return temp2;
        }
        else
        {
            return (temp1+temp2)/2;
        }
    }
}

/*
执行用时 :22~44 ms
内存消耗 :7.6~7.7MB
*/
double findMedianSortedArrays(  int*    nums1       ,
                                int     nums1Size   ,
                                int*    nums2       ,
                                int     nums2Size
                            )
{

    int     temp        =   nums1Size   ;
    int*    nums        =   NULL        ;
    int     type        =   0           ;
    int     loc1        =   0           ;
    int     loc2        =   0           ;
    int     count       =   0           ;
    int     i           =   0           ;
    int     j           =   0           ;
    double  temp0       =   0.0         ;
    double  temp1       =   0.0         ;
    double  temp2       =   0.0         ;


    if(nums1Size<nums2Size)
    {
        temp        =   nums1Size   ;
        nums1Size   =   nums2Size   ;
        nums2Size   =   temp        ;
        nums        =   nums1       ;
        nums1       =   nums2       ;
        nums2       =   nums        ;   
    }

    type = (nums1Size % 2 + nums2Size % 2) % 2;
    loc1 = (nums1Size - nums2Size)/2 + nums2Size -1 ;
    loc2 = loc1+1;

    if(  (nums1Size==0)
       &&(nums2Size==0)
    )
    {
        return 0.0;
    }
    else if(nums2Size ==0)
    {
        if(nums1Size%2==0)
        {
            return (double)(nums1[nums1Size/2-1]+nums1[nums1Size/2])/2.0;
        }
        else
        {
            return (double)(nums1[nums1Size/2]);
        }
        
    }
    else if (nums1Size ==0)
    {
        if(nums2Size%2==0)
        {
            return (double)(nums2[nums2Size/2-1]+nums2[nums2Size/2])/2.0;
        }
        else
        {
            return (double)(nums2[nums2Size/2]);
        }       
    }
    else
    {
        while (1)
        {
            if(  (i<nums1Size)
               &&(j<nums2Size)
            )
            {
                if(nums1[i]<=nums2[j])
                {
                    temp0 = nums1[i];
                    i++;

                }
                else
                {
                    temp0 = nums2[j];
                    j++;

                }

            }
            else if(i<nums1Size)
            { 
                temp0 = nums1[i];
                i++;

            }
            else if(j<nums2Size)
            {
                temp0 = nums2[j];
                j++;

            }
            else
            {
                break;    
            }

            if(count==loc1)
            {
                temp1 = temp0;
            }
            if(count==loc2)
            {
                temp2 = temp0;
                break;
            }
            count++;
        }
        if(type == 1)
        {
            return temp2;
        }
        else
        {
            return (temp1+temp2)/2;
        }
    }
}

/*
执行结果：
通过
显示详情
执行用时 :24 ms, 在所有 C 提交中击败了63.63% 的用户
内存消耗 :7.6 MB, 在所有 C 提交中击败了87.35%的用户
*/

