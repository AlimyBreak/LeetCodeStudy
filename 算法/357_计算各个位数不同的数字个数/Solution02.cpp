class Solution
{
    
    public:
        int countNumbersWithUniqueDigits(int n)
        {
            int ret_val = 0;
            int temp    = 0;
            int arr[10] = {9,9,8,7,6,5,4,3,2,1};
            int i = 0;
            int j = 0;
            
            if(n < 0)
            {
                return ret_val;
            }
            
            if(n > 10)
            {
                n = 10;
            }
            
            ret_val = 1;
            
            for( i = 1; i <= n ; i++)
            {
                temp = 1;
                for(j = 0 ; j < i ; j++)
                {
                    temp *= arr[j];
                }
                
                ret_val += temp;
            }
            

            return ret_val;
        }
};
/*
执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 cpp 提交中击败了100.00% 的用户
内存消耗 :8.1 MB, 在所有 cpp 提交中击败了72.30%的用户
*/
