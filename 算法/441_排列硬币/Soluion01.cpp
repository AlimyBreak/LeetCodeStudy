class Solution
{
    public:
        int arrangeCoins(int n)
        {
            int level = 1;
            
            while(n >= level)
            {
                n -= level;
                level++;
            }
            return level-1;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :16 ms, 在所有 cpp 提交中击败了47.14% 的用户
内存消耗 :8.1 MB, 在所有 cpp 提交中击败了90.74%的用户
*/