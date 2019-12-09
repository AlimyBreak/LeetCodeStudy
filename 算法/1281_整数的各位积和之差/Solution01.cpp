class Solution
{
    public:
        int subtractProductAndSum(int n)
        {
            if(n < 1)
            {
                return 0;
            }

            int sum     =   0;
            int product =   1;
            int temp    =   0;
            while(n!=0)
            {
                temp    =   n % 10  ;
                sum     +=  temp    ;
                product *=  temp    ;
                n       /=  10      ; 
            }
            return (product-sum);
    }
};

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 cpp 提交中击败了100.00% 的用户
内存消耗 :8.1 MB, 在所有 cpp 提交中击败了100.00%的用户
*/