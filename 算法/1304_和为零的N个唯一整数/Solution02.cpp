class Solution
{
    public:
        vector<int> sumZero(int n)
        {
            vector<int> ret_val ;
            int temp = 0;
            int i = 0;
            if(n > 1)
            {
                for( i = 1; i < n ; i++)
                {
                    temp += i;
                    ret_val.push_back(i);
                }
                
                ret_val.push_back(-temp);
                
            }
            else if(n == 1)
            {
                ret_val.push_back(0);
            }
            return ret_val;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了99.21% 的用户
内存消耗 :9.3 MB, 在所有 C++ 提交中击败了100.00%的用户
*/