class Solution
{
    public:
        bool canThreePartsEqualSum(vector<int>& A)
        {
            int     sum_all     =   0       ;
            int     i           =   0       ;
            int     target      =   0       ;
            int     left        =   0       ;
            int     right       =   0       ;
            int     left_sum    =   0       ;
            int     right_sum   =   0       ;
            
            for(i = 0 ; i < A.size();i++)
            {
                sum_all +=  A[i];
            }
            
            if(sum_all%3)
            {
                return false;
            }
            else
            {
                target = sum_all / 3 ;
                
                left    = 0;
                right   = A.size()-1;
                
                while(left < A.size() )
                {
                    left_sum += A[left];
                    if(left_sum == target)
                    {
                        break;
                    }
                    left++;
                }
                
                while(right >= 0)
                {
                    right_sum += A[right];
                    if(right_sum == target)
                    {
                        break;
                    }
                    right--;
                }
                return ((right - left) > 0);
            }            
        }
};

/*
执行结果：
通过
显示详情
执行用时 :60 ms, 在所有 cpp 提交中击败了75.85% 的用户
内存消耗 :12.6 MB, 在所有 cpp 提交中击败了49.40%的用户
*/