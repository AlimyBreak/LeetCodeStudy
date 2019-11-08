class Solution
{
    public:
        int arrangeCoins(int n)
        {
            return (int)((sqrt(1 + ((long long)n <<3)) - 1) / 2);
        }
};


/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 cpp 提交中击败了79.15% 的用户
内存消耗 :8.1 MB, 在所有 cpp 提交中击败了86.30%的用户
*/