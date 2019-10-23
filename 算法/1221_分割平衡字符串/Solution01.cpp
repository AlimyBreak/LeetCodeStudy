class Solution
{
    public:
        int balancedStringSplit(string s)
        {
            int ret_val = 0;
            int i       = 0;
            int count   = 0'
            for(i=0;i<s.size();i++)
            {
                if(s[i] == 'L')
                {
                    count++;
                }
                else
                {
                    count--;
                }
                if(count==0)
                {
                    ++ret_val;
                }
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 cpp 提交中击败了70.43%的用户
内存消耗 :8.4 MB, 在所有 cpp 提交中击败了100.00%的用户
*/