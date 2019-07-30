class Solution
{
    public:
        int tribonacci(int n)
        {
            if(n<=0)
            {
                return 0;
            }
            if(n==1)
            {
                return 1;
            }
            if(n==2)
            {
                return 1;
            }
            return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        }
};

/*
执行结果：
超出时间限制
显示详情
最后执行的输入：
33
*/

