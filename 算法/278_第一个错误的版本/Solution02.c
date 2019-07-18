
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    
    int left  = 0;
    int right = n-1;
    int mid   = 0;
    int ret_val = -1;
    bool flag_1 = false;
    bool flag_2 = false;
    
    
    if(n==1)
    {
        return 1;
    }
    
    if(n<1) /*不符合题设定义*/
    {
        return -1;
    }
    
    while(left<=right)
    {
        mid = left+(right-left)/2;
        if(isBadVersion(mid)==false)
        {
            if(isBadVersion(mid+1)==true)
            {
                ret_val = mid+1;
                break;
            }
            else
            {
                left = mid + 1;
            }
            
        }
        else
        {
            right = mid - 1;
        }
    }
    return ret_val;
}

/*
执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 C 提交中击败了100.00% 的用户
内存消耗 :6.6 MB, 在所有 C 提交中击败了58.55%的用户
*/