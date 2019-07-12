int numOfFactor5(int x)
{
    int num = 0;
    while(x%5==0)
    {
        num++;
        x /= 5 ;
    }
    return num;
}

int trailingZeroes(int n)
{
    int ret_num = 0;
    int i = 5;
    do 
    {
        if(n<=0)
        {
            break;
        }
        
        while(i<=n)
        {
            ret_num += numOfFactor5(i);
            i += 5;
        }
    }while(0);
    return ret_num;
}

/*
第一次提交
500 / 502 个通过测试用例
状态：超出时间限制
提交时间：1 分钟之前
最后执行的输入：
1808548329
2147483647
*/

