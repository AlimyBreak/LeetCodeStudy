class Solution
{
    public:
        void merge(vector<int>& A, int m, vector<int>& B, int n)
        {
            int i = 0;
            int j = 0;
            int k = 0;
            
            
            /* 拷贝*/
            for( i = m-1 ; i >= 0 ; i-- )
            {
                A[i+n] = A[i];
            }
            
            
            /*从小到大归并*/
            i = 0 ; 
            j = 0 ; 
            while(1)
            {
                if(i < m && j < n )
                {
                    if(A[n+i]<B[j])
                    {
                        A[k++] = A[n+i];
                        i++;
                    }
                    else
                    {
                        A[k++] = B[j];
                        j++;
                    }
                }
                else if(i < m )
                {
                    A[k++] = A[n+i];
                    i++;
                    
                }
                else if(j < n )
                {
                        A[k++] = B[j];
                        j++;
                }
                else
                {
                    break;
                }
                
            }
        }
};

class Solution
{
    public:
        void merge(vector<int>& A, int m, vector<int>& B, int n)
        {
            
            for( int i = 0;i < n; i++ )
            {
                A[m+i] = B[i];
            }
            
            sort(A.begin(),A.end());
        }
};


/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C++ 提交中击败了28.76% 的用户
内存消耗 :11.6 MB, 在所有 C++ 提交中击败了100.00%的用户
*/

