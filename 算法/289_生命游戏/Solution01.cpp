class Solution
{
    
    private:
    
        int __calLiveCells(vector<vector<int>>& vvi , int row , int col)
        {
        }
    public:
        void gameOfLife(vector<vector<int>>& board)
        {
            vector<vector<int>> bak(board);
            
            int rows = bak.size();
            int cols = bak[0].size();
            
            for(int i = 0 ; i < rows ; i++)
            {
                for(int j = 0 ; j < cols ; j++)
                {
                    int liveCount = __calLiveCells(bak,i,j);
                    switch(bak[i][j] << 4 + liveCount)
                    {
                        0x00:
                        0x01:
                        0x02:
                        0x04:
                        0x05:
                        0x06:
                        0x07:
                        0x08:
                            board[i][j] = 0;
                        break;
                        0x03:
                            board[i][j] = 1;
                        break;
                        
                        /* 活细胞 */
                        0x10:
                        0x11:
                            /*如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；*/
                            board[i][j] = 0;
                        break;
                        0x12:
                        0x13:
                            /*如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；*/
                            board[i][j] = 1;
                        break;
                        0x14:
                        0x15:
                        0x16:
                        0x17:
                        0x18: 
                            /*如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；*/
                            board[i][j] = 0;
                        break;
                        default: break;
                    }
                }
            }
        }
};