class Solution
{
    private:
        void __reverse_row(vector<vector<int>>& A , int row )
        {
            for(int i = 0 ; i < A[row].size() ; i++)
            {
                A[row][i] ^= 0x01;
            }
        }
        
        void __reverse_col(vector<vector<int>>& A , int col )
        {
            for(int i = 0 ; i < A.size() ; i++)
            {
                A[i][col] ^= 0x01;
            }
        }
        
    public:
        int matrixScore(vector<vector<int>>& A)
        {
            int ret_val = 0;
            int count   = 0;
            
            /*处理第一列*/
            for(int i = 0; i < A.size();i++)
            {
                if(A[i][0]==0)
                {
                   __reverse_row(A,i);
                }
            }
            
            /*处理后续的列*/
            for(int i = 1 ; i < A[0].size() ; i++)
            {
                count = 0;
                for(int j = 0 ; j < A.size(); j++)
                {
                    count += A[j][i];
                }
                
                if(count*2 < A.size())
                {
                    __reverse_col(A,i);
                }
            }
            
            /* 计算结果*/
            for(int i = 0 ; i < A.size(); i ++)
            {
                count = 0 ; 
                for(int j = 0; j < A[0].size(); j++)
                {
                    count *= 2;
                    count += A[i][j];
                }
                ret_val += count;
            }
            
            return ret_val;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了88.03% 的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了83.50%的用户
*/



class Solution
{
    private:
        void __reverse_row(vector<vector<int>>& A , int row )
        {
            int length = A[row].size();
            for(int i = 0 ; i < length; i++)
            {
                A[row][i] ^= 0x01;
            }
        }
        
        void __reverse_col(vector<vector<int>>& A , int col )
        {
            int length = A.size();
            for(int i = 0 ; i < length; i++)
            {
                A[i][col] ^= 0x01;
            }
        }
        
    public:
        int matrixScore(vector<vector<int>>& A)
        {
            int ret_val = 0;
            int count   = 0;
            
            int rows = A.size();
            int cols = A[0].size();
            
            /*处理第一列*/
            for(int i = 0; i < rows;i++)
            {
                if(A[i][0]==0)
                {
                   __reverse_row(A,i);
                }
            }
            
            /*处理后续的列*/
            for(int i = 1 ; i < cols ; i++)
            {
                count = 0;
                for(int j = 0 ; j < rows; j++)
                {
                    count += A[j][i];
                }
                
                if(count*2 < rows)
                {
                    __reverse_col(A,i);
                }
            }
            
            /* 计算结果*/
            for(int i = 0 ; i < rows; i ++)
            {
                count = 0 ; 
                for(int j = 0; j < cols; j++)
                {
                    count *= 2;
                    count += A[i][j];
                }
                ret_val += count;
            }
            
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了88.03% 的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了80.58%的用户
*/