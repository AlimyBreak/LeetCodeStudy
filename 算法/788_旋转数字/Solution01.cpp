class Solution
{
    
    private:
        bool isGoodNum(int n)
        {
            //int num_1 = 0;  /*0 1 8 2 5 6 9 个数*/
            int num_2 = 0;  /*2 5 6 9 个数*/
            
            while(n)
            {
                switch(n%10)
                {
                    case 2:
                    case 5:
                    case 6:
                    case 9:
                        //num_1++;
                        num_2++;
                    break;
                    
                    case 0:
                    case 1:
                    case 8:
                        //num_1++;
                    break;
                    
                    default:
                        return false;
                }
                n /= 10;
            }
            
            return (num_2>0);
            
        }
    
    public:
        int rotatedDigits(int N)
        {
            int ret_val =  0;
            
            for(int i=1;i <= N;i++ )
            {
                if(isGoodNum(i))
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
执行用时 :8 ms, 在所有 C++ 提交中击败了63.34% 的用户
内存消耗 :8.2 MB, 在所有 C++ 提交中击败了82.81%的用户
*/