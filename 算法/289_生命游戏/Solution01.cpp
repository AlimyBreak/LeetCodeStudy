class Solution
{
    private:
        int __calLiveCells(vector<vector<int>>& vvi , int row , int col)
        {
            int ret_val = 0;
            
            /*左上*/
            if(row > 0 && col > 0)
            {
                ret_val += vvi[row-1][col-1];
            }
            
            /*左中*/
            if( col > 0)
            {
                ret_val += vvi[row][col-1];
            }
            /*左下*/
            if(row+1 < vvi.size() && col > 0)
            {
                ret_val += vvi[row+1][col-1];
            }

            /*中上*/
            if(row > 0)
            {
                ret_val += vvi[row-1][col];
            }
            
            /*中下*/
            if(row+1 < vvi.size())
            {
                ret_val += vvi[row+1][col];
            }


            /*右上*/
            if(row>0 && col+1 < vvi[0].size())
            {
                ret_val += vvi[row-1][col+1];
            }

            /*右中*/
            if(col+1 < vvi[0].size())
            {
                ret_val += vvi[row][col+1];
            }

            /*右下*/
            if(row+1 < vvi.size() && col+1 < vvi[0].size())
            {
                ret_val += vvi[row+1][col+1];
            }
            return ret_val;
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
                    switch((bak[i][j] << 4) + liveCount)
                    {
                        case 0x00:
                        case 0x01:
                        case 0x02:
                        case 0x04:
                        case 0x05:
                        case 0x06:
                        case 0x07:
                        case 0x08:
                            board[i][j] = 0;
                        break;
                        case 0x03:
                            board[i][j] = 1;
                        break;
                        
                        /* 活细胞 */
                        case 0x10:
                        case 0x11:
                            /*如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；*/
                            board[i][j] = 0;
                        break;
                        case 0x12:
                        case 0x13:
                            /*如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；*/
                            board[i][j] = 1;
                        break;
                        case 0x14:
                        case 0x15:
                        case 0x16:
                        case 0x17:
                        case 0x18: 
                            /*如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；*/
                            board[i][j] = 0;
                        break;
                        default: break;
                    }
                }
            }
        }
};


/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 cpp 提交中击败了82.40% 的用户
内存消耗 :8.8 MB, 在所有 cpp 提交中击败了19.85%的用户
*/