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
        
        
        bool helper( vector<vector<char>>& board ,int index)
        {
            
            ///*每次不必从第0行第0列开始找*/
            for(int i = index ; i < 81;i++)
            {
                if(board[i/9][i%9]=='.')
                {
                    for(char c = '1'; c<='9';c++)
                    {
                        if(isValidc(c,i/9,i%9,board))
                        {
                            board[i/9][i%9] = c;
                            if(helper(board,index+1))
                                return true;
                            board[i/9][i%9] = '.';
                            
                        }
                    }
                    return false; /*1~9每一个插进去都冲突*/
                    
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
内存消耗 :8.6 MB, 在所有 cpp 提交中击败了88.83%的用户
*/