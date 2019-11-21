class Solution
{
    
    private:
        int __neighborAver(vector<vector<int>>& M , int rows , int cols , int row , int col)
        {
            int temp    =   M[row][col];
            int count   =   1;
            
            /*上一行*/
            if(row-1>=0)
            {
                temp += M[row-1][col];
                count++;
                if(col-1 >=0)
                {
                    temp += M[row-1][col-1];
                    count++;
                }
                
                if(col+1 < cols)
                {
                    temp += M[row-1][col+1];
                    count++;
                }
            }
            
            /*下一行*/
            if(row+1< rows)
            {
                temp += M[row+1][col];
                count++;
                if(col-1 >=0)
                {
                    temp += M[row+1][col-1];
                    count++;
                }
                
                if(col+1 < cols)
                {
                    temp += M[row+1][col+1];
                    count++;
                }                
            }
            
            /*中间一行*/
            if(col-1 >=0)
            {
                temp += M[row][col-1];
                count++;
            }
            
            if(col+1 < cols)
            {
                temp += M[row][col+1];
                count++;
            }
            
            return (int)(temp/count);
        }
        
    public:
        vector<vector<int>> imageSmoother(vector<vector<int>>& M)
        {
            int r   =   M.size();
            int c   =   M[0].size();
            
            vector<vector<int>> vvi(r,vector<int>(c,0));
            
            for(int i = 0; i < r; i++)
            {
                for(int j = 0 ; j < c; j++)
                {
                    vvi[i][j] = __neighborAver(M,r,c,i,j);
                }
            }
            return vvi;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :168 ms, 在所有 cpp 提交中击败了97.11% 的用户
内存消耗 :17.4 MB, 在所有 cpp 提交中击败了88.18%的用户
*/