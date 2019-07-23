int hammingDistance(int x, int y)
{
    unsigned int z = 0;
    
    int count = 0;
    
    z = (unsigned int)(x)^(unsigned int)(y);
    while(z!=0xffffffff)
    {
        count++;
        z = z|(z+1);
    }
    return (32-count);
}

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了82.65% 的用户
内存消耗 :6.8 MB, 在所有 C 提交中击败了65.13%的用户
*/