// https://leetcode-cn.com/problems/sudoku-solver/

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
        
        
        bool helper( vector<vector<char>>& board )
        {
            /* 每次都从第0行第0列这个点找起,防止漏点.*/
            for(int i = 0 ; i < 9 ; i++)
            {
                for(int j = 0 ; j < 9 ; j++)
                {
                    if(board[i][j]=='.')
                    {
                        for(char c = '1'; c<='9';c++)
                        {
                            if(isValidc(c,i,j,board))
                            {
                                board[i][j] = c;
                                if(helper(board))
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
            helper(board);   
        }
};
/*
执行结果：
通过
显示详情
执行用时 :20 ms, 在所有 cpp 提交中击败了43.56% 的用户
内存消耗 :8.5 MB, 在所有 cpp 提交中击败了97.42%的用户
*/