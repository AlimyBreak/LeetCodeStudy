class Solution
{
    public:
        int minAddToMakeValid(string S)
        {
            int left    = 0;
            int right   = 0;
            
            for(int i = 0 ; i < S.size() ; i++)
            {
                if(S[i] == '(')
                {
                    left++;
                }
                else
                {
                    right++;
                    if(left>0)
                    {
                        left--;
                        right--;
                    }
                }
                

            }
            
            return left+right;
            
        }
};

/*
执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 cpp 提交中击败了100.00% 的用户
内存消耗 :8.5 MB, 在所有 cpp 提交中击败了85.63%的用户
*/