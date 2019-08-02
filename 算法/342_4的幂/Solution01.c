bool isPowerOfFour(int num)
{
    int count  = 0   ;
    int temp   = num ;
    
    if(num <=0)
    {
        return false;
    }
    
    temp = temp & (temp -1);
    
    if(  ( temp == 0            )
       &&( num &   0x55555555   )
    )
    {
        return true;
    }
    return false;
}

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了84.62% 的用户
内存消耗 :6.9 MB, 在所有 C 提交中击败了5.95%的用户
*/