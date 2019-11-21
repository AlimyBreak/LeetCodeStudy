class Solution
{
    
    private:
        void __neighborAver(vector<vector<int>>& M , int rows , int cols , int row , int col)
        {
            int temp    =   (M[row][col] & 0xff);
            int count   =   1;
            
            /*上一行*/
            if(row-1>=0)
            {
                temp += (M[row-1][col] & 0xff);
                count++;
                if(col-1 >=0)
                {
                    temp += (M[row-1][col-1] & 0xff);
                    count++;
                }
                
                if(col+1 < cols)
                {
                    temp += (M[row-1][col+1] &  0xff);
                    count++;
                }
            }
            
            /*下一行*/
            if(row+1< rows)
            {
                temp += (M[row+1][col] & 0xff);
                count++;
                if(col-1 >=0)
                {
                    temp += (M[row+1][col-1] &  0xff);
                    count++;
                }
                
                if(col+1 < cols)
                {
                    temp += (M[row+1][col+1]& 0xff);
                    count++;
                }                
            }
            
            /*中间一行*/
            if(col-1 >=0)
            {
                temp += (M[row][col-1]& 0xff);
                count++;
            }
            
            if(col+1 < cols)
            {
                temp += (M[row][col+1] & 0xff);
                count++;
            }
            
            (( unsigned char*)(&M[row][col]))[1] = temp/count;
            // M[i][j] |= (temp/count)<<8;
        }
        
    public:
        vector<vector<int>> imageSmoother(vector<vector<int>>& M)
        {
            int r   =   M.size()    ;
            int c   =   M[0].size() ;
            int i   =   0           ;
            int j   =   0           ;
            
            /*计算8~15bit*/
            for(i = 0; i < r; i++)
            {
                for(j = 0 ; j < c; j++)
                {
                    __neighborAver(M,r,c,i,j);
                }
            }

            /*保留8~15bit--->0~7bit*/
            for(i = 0; i < r; i++)
            {
                for(j = 0 ; j < c; j++)
                {
                    // M[i][j] >>= 8;
                    M[i][j] = (( unsigned char*)(&M[i][j]))[1];
                }
            }


            return M;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :264 ms, 在所有 cpp 提交中击败了31.23% 的用户
内存消耗 :17.6 MB, 在所有 cpp 提交中击败了79.09%的用户
https://leetcode-cn.com/submissions/detail/37351245/
*/


/*
使用位操作时.
M[i][j] >>= 8;
M[i][j] |= (temp/count)<<8;
执行用时 :152 ms, 在所有 cpp 提交中击败了100.00% 的用户
内存消耗 :17.4 MB, 在所有 cpp 提交中击败了93.64%的用户
https://leetcode-cn.com/submissions/detail/37352559/
*/