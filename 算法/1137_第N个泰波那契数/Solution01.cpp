class Solution
{
    public:
        int tribonacci(int n)
        {
            int t[3]    =   {0,1,1}     ;
            int i       =   0           ;
            int temp    =   0           ;
        
            if(n<0)
            {
                return 1;
            }
            else if(n<=2)
            {
                return t[n];
            }
            else
            {
                while(n>=3)
                {
                    temp = t[0] + t[1] + t[2];
                    t[0] = t[1];
                    t[1] = t[2];
                    t[2] = temp;
                    n --;
                }
                return t[2];
            }
    }
};

/*
执行结果：通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.1 MB, 在所有 C++ 提交中击败了100.00%的用户
*/