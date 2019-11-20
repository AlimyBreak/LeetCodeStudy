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
            vector<pair<int,int>>  vpii;
            int i = 0; 
            int j = 0;
            
            /*1.遍历找0的位置*/
            for(i = 0 ; i < m ; i++)
            {
                for(j = 0 ; j < n ; j ++)
                {
                    if(matrix[i][j]==0)
                    {
                        vpii.push_back(make_pair(i,j));
                    }
                }
            }
            
            /*2.置零*/
            for(i = 0; i < vpii.size();i++)
            {
                setRowZero(matrix,vpii[i].first,n);
                setColZero(matrix,vpii[i].second,m);
            }            
        }

};


/*
执行结果：
通过
显示详情
执行用时 :60 ms, 在所有 cpp 提交中击败了74.42% 的用户
内存消耗 :11.5 MB, 在所有 cpp 提交中击败了30.16%的用户
*/