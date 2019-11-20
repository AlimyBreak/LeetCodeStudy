class Solution
{
    private:
        void setRowNeg(vector<vector<int>>& matrix, int row_number, int cols )
        {
            int i = 0 ; 
            for( i = 0 ; i < cols ; i++)
            {
                if(matrix[row_number][i]==0 || matrix[row_number][i]==-20000)
                {
                    matrix[row_number][i] = -20000;
                }
                else
                {
                    matrix[row_number][i] = -10000;
                }
            }
        }
        
        void setColNeg(vector<vector<int>>& matrix, int col_number, int rows)
        {
            int i = 0;
            for(i = 0; i < rows;i++)
            {
                if(matrix[i][col_number]==0 || matrix[i][col_number]==-20000)
                {
                    matrix[i][col_number] = -20000;
                }
                else
                {
                    matrix[i][col_number] = -10000;
                }
            }
        }
        
    public:
        void setZeroes(vector<vector<int>>& matrix)
        {
            int m   = matrix.size()     ;
            int n   = matrix[0].size()  ;
            int i   = 0                 ; 
            int j   = 0                 ;
            
            /*1.遍历找0的位置,并置负数*/
            for(i = 0 ; i < m ; i++)
            {
                for(j = 0 ; j < n ; j++)
                {
                    if(matrix[i][j]==0 || matrix[i][j]==-20000 )
                    {
                        setRowNeg(matrix,i,n);
                        setColNeg(matrix,j,m);
                    }
                }
            }
            
            /*2.挑出负数置0*/
            for(i = 0 ; i < m ; i++)
            {
                for(j = 0 ; j < n ; j++)
                {
                    if(matrix[i][j]==-10000 || matrix[i][j]==-20000)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        
};



/*
执行结果：
通过
显示详情
执行用时 :96 ms, 在所有 cpp 提交中击败了26.06% 的用户
内存消耗 :11.4 MB, 在所有 cpp 提交中击败了66.83%的用户
*/