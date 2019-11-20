class Solution
{
    private:
        void setRowZeros(vector<vector<int>>& matrix, int row_number, int cols )
        {
            int i = 0 ; 
            for( i = 0 ; i < cols ; i++)
            {
                matrix[row_number][i] = 0;
            }
        }
        
        void setColZeros(vector<vector<int>>& matrix, int col_number, int rows)
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
            int m       =   matrix.size()       ;
            int n       =   matrix[0].size()    ;
            int i       =   0                   ; 
            int j       =   0                   ;
            int temp    =   matrix[0][0]        ;/*备份matrix[0][0]*/
            
            /*1.遍历第0行和第0列,用matrix[0][0] 来记录

                temp = 0,则标记matrix[0][0]标记为0x03,表示最终结果第0行第0列都要置0.
                temp !=0,且第0行第0列都没有出现0,标记matrix[0][0]为0x00,表示最终结果第0行第0列都不需要置0.
                temp !=0,第0列出现0,但第0行没出现0,标记matrix[0][0]为0x01,表示最终结果第0行不需要置0,第0列需要置0.
                temp !=0,第0列没出现0,但第0行出现0,标记matrix[0][0]为0x02,表示最终结果第0行需要置0,第0列不需要置0.
                temp !=0,第0列出现0,第0行出现0,标记matrix[0][0]为0x03,表示最终结果第0行0列需要置0
            
            */
            if(temp==0)
            {
                matrix[0][0] = 3; /*第0行,第0列需要全部置0*/
            }
            else
            {
                matrix[0][0] = 0; /*默认不需要第0行和第0列置0*/
                for(i = 1 ; i < m ; i++)
                {
                    if(matrix[i][0]==0)
                    {
                        matrix[0][0] |= 0x01; /* 标记第0列需要置0*/
                        break;
                    }
                }
                
                for(i=1;i<n;i++)
                {
                    if(matrix[0][i]==0)
                    {
                        matrix[0][0] |= 0x02; /* 标记第0行需要置0*/
                        break;
                    }
                }
            }
            
            /*2.遍历第1~m-1行,第1~n-1列,若matrix[i][j]==0,就把 matrix[i][0] matrix[0][j]置0*/
            for(i = 1;i < m;i++)
            {
                for(j = 1;j < n; j++)
                {
                    if(matrix[i][j]==0)
                    {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
            
            /*3.
                遍历matrix[0][1~n-1],查看列是否需要置0,
                遍历matrix[1~m-1][0],查看那些行需要置0,
                查看matrix[0][0]的值,若为0,则需要从temp中恢复值,若为1则第0列需要置0,若为2则第0行需要置0,若为3则第0行和第0列都需要置0
            */
            
            for(i = 1;i < n ; i++)
            {
                if(matrix[0][i]==0)
                {
                    setColZeros(matrix,i,m);
                }
            }
            
            for(i = 1; i < m ; i++ )
            {
                if(matrix[i][0]==0)
                {
                    setRowZeros(matrix,i,n);
                }
            }
            
            switch(matrix[0][0])
            {
                case 0x00:
                    matrix[0][0] = temp;
                break;
                
                case 0x01:
                     setColZeros(matrix,0,m);
                break;
                
                case 0x02:
                    setRowZeros(matrix,0,n);
                break;
                case 0x03:
                    setRowZeros(matrix,0,n);
                    setColZeros(matrix,0,m);
                break;
                
                default:
                break;
            }
            

        }
        
};

/*
执行结果：
通过
显示详情
执行用时 :52 ms, 在所有 cpp 提交中击败了97.49% 的用户
内存消耗 :11.4 MB, 在所有 cpp 提交中击败了59.21%的用户
*/