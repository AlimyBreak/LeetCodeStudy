int hammingWeight(uint32_t n)
{
    int count = 0;
    while(n)
    {
        count++;
        n = n&(n-1);
    }
    
    return count;
    
}

/*
执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 C 提交中击败了100.00% 的用户
内存消耗 :6.9 MB, 在所有 C 提交中击败了6.02%的用户
*/