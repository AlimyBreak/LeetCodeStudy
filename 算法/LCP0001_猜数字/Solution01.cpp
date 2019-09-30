class Solution
{
    public:
        int game(vector<int>& guess, vector<int>& answer)
        {
            int ret_val = 0;

            for(int i = 0 ; i < 3 ; i++)
            {
                if(guess[i]==answer[i])
                {
                    ret_val++;
                }
            }
            return ret_val;
        }
};
/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了64.30% 的用户
内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户
*/


class Solution
{
    public:
        int game(vector<int>& guess, vector<int>& answer)
        {
            int ret_val = 0;

            for(int i = 0 ; i < 3 ; i++)
            {
                if(!(guess[i]^answer[i]))
                {
                    ret_val++;
                }
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了64.30% 的用户
内存消耗 :8.3 MB, 在所有 C++ 提交中击败了100.00%的用户
*/