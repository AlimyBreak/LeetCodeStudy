class Solution
{
    public:
        int maximum69Number(int num)
        {
            char arr[4] = {0,0,0,0};
            
            arr[0] = (num/1000)     ;   // 千
            arr[1] = (num/100)%10   ;   // 百
            arr[2] = (num/10)%10    ;   // 十
            arr[3] = (num%10)       ;   // 个
            
            for(int i = 0 ; i < 4;i++)
            {
                if(arr[i]==6)
                {
                    arr[i]=9;
                    break;
                }
            }
            
            int ret_val = 0;
            for(int i = 0 ; i < 4 ; i++)
            {
                ret_val = ret_val * 10 + arr[i];
            }
            return ret_val;
            
            
        }
};


/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了63.54% 的用户
内存消耗 :8 MB, 在所有 C++ 提交中击败了100.00%的用户
*/