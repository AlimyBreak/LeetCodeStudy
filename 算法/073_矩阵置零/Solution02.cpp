class Solution
{
    
    private:

        void setRowZero(vector<vector<int>>& matrix, int row_number, int cols )
        {
            int i = 0 ; 
            
            for( i = 0 ; i < cols ; i++)
            {
                matrix[row_number][i] = 0;
            }
        }
        
        
        void setColZero(vector<vector<int>>& matrix, int col_number, int rows)
        {
            int i = 0;
            for(i = 0; i < rows;i++)
            {
                matrix[i][col_number] = 0;
            }
        }
    
    
    public:
        void setZeroes(vector<vector<int>>& matrix)
        {
            int m = matrix.size();
            int n = matrix[0].size();
            //vector<pair<int,int>>  vpii;
            
            map<int,int> mii_row;
            map<int,int> mii_col;
            
            int i = 0; 
            int j = 0;
            
            /*1.遍历找0的位置*/
            for(i = 0 ; i < m ; i++)
            {
                for(j = 0 ; j < n ; j ++)
                {
                    if(matrix[i][j]==0)
                    {
                        mii_row[i] = 0;
                        mii_col[j] = 0;
                        
                    }
                }
            }
            
            /*2.置零*/
            map<int, int>::iterator  iter = mii_row.begin();
            while(iter!=mii_row.end())
            {
                setRowZero(matrix,iter->first,n);
                iter++;
            }
            
            iter = mii_col.begin();
            while(iter != mii_col.end())
            {
                setColZero(matrix,iter->first,m);
                iter++;   
            }
        }
};


/*
执行结果：
通过
显示详情
执行用时 :56 ms, 在所有 cpp 提交中击败了89.67% 的用户
内存消耗 :11.6 MB, 在所有 cpp 提交中击败了11.11%的用户
*/