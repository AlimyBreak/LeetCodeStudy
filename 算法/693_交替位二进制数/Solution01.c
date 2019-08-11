

bool hasAlternatingBits(int n)
{
    unsigned int temp = (n^(n>>1));
    if(temp !=2147483647 ) 
    {
        return (temp&(temp+1))==0;
    }
    else
    {
        // 对应特殊值(n==1431655765)
        return true;
    }
}

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了69.14% 的用户
内存消耗 :6.7 MB, 在所有 C 提交中击败了81.13%的用户
*/