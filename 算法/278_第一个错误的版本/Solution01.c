// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n)
{    
    int left    = 0;
    int right   = n-1;
    int mid     = 0;
    int ret_val = -1;
    bool flag_1 = false;
    bool flag_2 = false;
    
    if(n==1)    /*只有一个版本,那说个球,不需要二分,直接处理*/
    {
        return 1;
    }
    
    if(n<1) /*不符合题设定义*/
    {
        return -1;
    }
    
    while(left<=right)
    {
        mid     =   left+(right-left)/2;    /* 防加法溢出*/
        flag_1  =   isBadVersion(mid);
        flag_2  =   isBadVersion(mid+1);
        
        if(  (flag_1==false)    /*找着啦*/
           &&(flag_2==true)
        )
        {
            ret_val = mid+1;
            break;
        }
        
        if(  (flag_1==false)    /*还处在全部正确版本的区域*/
           &&(flag_2==false)
        )
        {
            left = mid + 1;
        }
        
        if(flag_1==true)/*已经处在错误版本的区域*/
        {
            right = mid -1;
        }   
    }
    return ret_val;
}
/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了85.64% 的用户
内存消耗 :6.7 MB, 在所有 C 提交中击败了7.24%的用户
*/