class Solution
{
    public:
        vector<int> sumZero(int n)
        {
            vector<int> ret_val ;
            if(n >= 1)
            {
                /*奇数*/
                if(n % 2)
                {
                    ret_val.push_back(0);
                }
                
                for(int i = 1 ; i <= n / 2 ; i++)
                {
                    ret_val.push_back(-i);
                    ret_val.push_back(i); 
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
内存消耗 :9.1 MB, 在所有 C++ 提交中击败了100.00%的用户
*/