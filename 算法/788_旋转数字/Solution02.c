

bool __isGoodNum(int n)
{
    int num_2 = 0;  /*2 5 6 9 个数*/
    while(n)
    {
        switch(n%10)
        {
            case 2:
            case 5:
            case 6:
            case 9:
                num_2++;
            break;
            
            case 0:
            case 1:
            case 8:
            break;
            
            default:
                return false;
        }
        n /= 10;
    }
    
    return (num_2>0);    
}


int rotatedDigits(int N)
{
    int ret_val = 0;
    for(int i = 2; i <= N ; i ++)
    {
        if(__isGoodNum(i))
        {
            ret_val ++;
        }
    }
    return ret_val;
}




/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了86.00% 的用户
内存消耗 :6.8 MB, 在所有 C 提交中击败了45.71%的用户
*/