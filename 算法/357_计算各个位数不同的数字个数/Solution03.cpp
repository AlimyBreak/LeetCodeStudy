class Solution
{
    
    public:
        int countNumbersWithUniqueDigits(int n)
        {
            int ret_val = 0;
            int arr[11] = {1,10,91,739,5275,32491,168571,712891,2345851,5611771,8877691};
            if(n>=0)
            {
                if(n>=10)
                {
                    n = 10;
                }
                ret_val = arr[n];
            }
            

            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 cpp 提交中击败了100.00% 的用户
内存消耗 :8 MB, 在所有 cpp 提交中击败了89.86%的用户
*/