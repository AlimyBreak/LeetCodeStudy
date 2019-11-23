class Solution
{
    
    private:
        
        
        bool isValidc   (   char                    c       ,
                            int                     row     ,
                            int                     col     ,
                            vector<vector<char>>&   board 
                        )
        {
            
            for(int i = 0 ; i < 9 ; i++)
            {
                // 横
                if(board[row][i]==c)
                {
                    return false;
                }
                // 竖
                if(board[i][col]==c)
                {
                    return false;
                }
                //小正方形
                if(board[(row / 3)*3 + i / 3][(col / 3) * 3 + i % 3]==c)
                {
                    return false;
                }
                
            }
            
            return true;
            
        }
        
        
        bool helper( vector<vector<char>>& board ,int row)
        {
            
            /*每次不必从第0行第0列开始找*/
            for(int i = row ; i < 9 ; i++)
            {
                for(int j = 0 ; j < 9 ; j++) //  这里j不能初始化为 col ,会漏掉一堆点
                {
                    if(board[i][j]=='.')
                    {
                        for(char c = '1'; c<='9';c++)
                        {
                            if(isValidc(c,i,j,board))
                            {
                                board[i][j] = c;
                                if(helper(board,(i*9+j+1)/9))
                                    return true;
                                board[i][j] = '.';
                            }
                        }
                        
                        return false; /*九个数没一个数能插入的,说明上一层处理得不对*/
                    }
                }
                
            }
            
            
            return true;
        }
    
    
    public:
        void solveSudoku(vector<vector<char>>& board)
        {
            helper(board,0);   
        }
};


/*
执行结果：
通过
显示详情
执行用时 :20 ms, 在所有 cpp 提交中击败了43.56% 的用户
内存消耗 :8.7 MB, 在所有 cpp 提交中击败了83.95%的用户
*/