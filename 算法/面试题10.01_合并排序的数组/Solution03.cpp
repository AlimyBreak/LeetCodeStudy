class Solution
{
    public:
        void merge(vector<int>& A, int m, vector<int>& B, int n)
        {
            int i = m-1;
            int j = n-1;
            int k = m+n-1;
            
            
            
            /*从大到小归并*/
            while(1)
            {
                if(i >= 0 && j >= 0 )
                {
                    if(A[i]<B[j])
                    {
                        A[k--] = B[j--];
                    }
                    else
                    {
                        A[k--] = A[i--];
                    }
                }
                else if(i >= 0 )
                {
                    A[k--] = A[i--];
                }
                else if(j >= 0 )
                {
                        A[k--] = B[j--];
                }
                else
                {
                    break;
                }
                
            }
        }
};


/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了78.97% 的用户
内存消耗 :11.6 MB, 在所有 C++ 提交中击败了100.00%的用户
*/