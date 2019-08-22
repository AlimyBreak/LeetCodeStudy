
int getKth  (   int*    nums1   ,
                int     start1  ,
                int     end1    ,
                int*    nums2   ,
                int     start2  ,
                int     end2    ,
                int     k           /*要找第k小的数(k=1,2,3,...)*/
            )
{
    int len1    =   end1 - start1 + 1   ;
    int len2    =   end2 - start2 + 1   ;
    int i       =   start1              ;
    int j       =   start2              ;
    
    if(len1 > len2) /*保证len1<=len2*/
    {
        return getKth(nums2,start2,end2,nums1,start1,end1,k);
    }
    /* 递归结束条件1,某个数组已经全是比第k小的数*/
    if((len1==0)&&(len2==0)) 
    {
        return 0;/*若一开始输入的就是两个长度为0的数组,直接返回*/
    }
    else if(len1 == 0)
    {
        return nums2[start2+k-1];
    }
    /* 递归结束条件2,找到最小点数据(第1小)*/
    if(k==1)
    {
        return nums1[start1] <= nums2[start2] ? nums1[start1] : nums2[start2];
    }

    /*取要求长度和现有长度的较小值作为比较索引,防止访问越界*/
    i += (len1 <= k/2 ? len1 : k/2 ) - 1;
    j += (len2 <= k/2 ? len2 : k/2 ) - 1;
    
    if(nums1[i]>nums2[j])
    {
        return getKth(nums1,start1,end1,nums2,j+1,end2,k-(j-start2+1));
    }
    else
    {
        return getKth(nums1,i+1,end1,nums2,start2,end2,k-(i-start1+1));
    }
}

double findMedianSortedArrays(  int*        nums1       ,
                                int         nums1Size   ,
                                int*        nums2       ,
                                int         nums2Size
                            )
{
    unsigned int left    =   (nums1Size + nums2Size+1 )/2      ;  /*用unsigned int 做防溢出*/
    unsigned int right   =   (nums1Size + nums2Size   )/2 + 1    ;

    if(left!=right)
    {
        return  0.5*(getKth(nums1,0,nums1Size-1,nums2,0,nums2Size-1,left) + getKth(nums1,0,nums1Size-1,nums2,0,nums2Size-1,right) );
    }
    else
    {
        return getKth(nums1,0,nums1Size-1,nums2,0,nums2Size-1,left);
    }
}

/*
执行结果：
通过
显示详情
执行用时 :16 ms, 在所有 C 提交中击败了95.77% 的用户
内存消耗 :7.4 MB, 在所有 C 提交中击败了95.45%的用户
*/