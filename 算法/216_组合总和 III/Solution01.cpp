class Solution
{
    private:
        int bit1Count(unsigned int n)
        {
            int count = 0;
            while (n)
            {
                count++;
                n &= (n - 1);
            }
            return count;
        }
    public:
        vector<vector<int>> combinationSum3(int k, int n)
        {
            unsigned int    i = 0;
            int             j = 0;
            vector<int>     temp;
            vector<vector<int>> ret_val;
            int sum = 0;
            for (i = 0; i < 512; i++)
            {
                if (bit1Count(i) == k)
                {
                    temp.clear();
                    sum = 0;
                    for (j = 0; j < 9; j++)
                    {
                        if (i & (0x01 << j))
                        {
                            temp.push_back(j + 1);
                            sum += (j + 1);
                        }
                    }
                    if (sum == n)
                    {
                        ret_val.push_back(temp);
                    }
                }
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :8.4 MB, 在所有 C++ 提交中击败了92.65%的用户
*/