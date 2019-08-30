int peakIndexInMountainArray(   int*    A       ,
                                int     ASize
                            )
{
    int left    =   0           ;
    int mid     =   0           ;
    int right   =   ASize - 1   ;
    
    while(left<=right)
    {
        mid = left + (right - left) / 2;
        if(    (A[mid]>A[mid-1])
            && (A[mid+1]>A[mid])
        )
        {
            left = mid + 1;
        }
        else if(    (A[mid]<A[mid-1])
                &&  (A[mid+1]<A[mid])        
        )
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }   
    }
    return -1;
}

/*
执行结果：
通过
显示详情
执行用时 :16 ms, 在所有 C 提交中击败了77.08% 的用户
内存消耗 :7.6 MB, 在所有 C 提交中击败了55.13%的用户
*/