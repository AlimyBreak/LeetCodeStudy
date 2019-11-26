class Solution
{
    
    private:
    
        int arr[8] = {-1,0,1,0,0,-1,0,+1};
        bool helper(    vector<vector<char>>&   board       ,
                        string&                 word        ,
                        int                     cur_idx     ,
                        int                     cur_row     ,
                        int                     cur_col     ,
                        vector<vector<int>>&    visited
                   )
        {
            
            if(cur_idx == word.size())
            {
                return true;
            }
            
            if(cur_row<0 || cur_row >= board.size() || cur_col < 0 || cur_col >= board[0].size())
            {
                return false;
            }
            
            if(visited[cur_row][cur_col]==1)
            {
                return false;
            }
            
            if(board[cur_row][cur_col]!=word[cur_idx])
            {
                return false;
            }
            else
            {
                visited[cur_row][cur_col] = 1;
                for(int i = 0 ; i < 4 ; i++)
                {
                    if(helper(board,word,cur_idx+1,cur_row+arr[2*i],cur_col+arr[2*i+1],visited))
                        return true;
                    
                }
                visited[cur_row][cur_col] = 0;
            }
            return false;
        }
    
    
    public:
        bool exist( vector<vector<char>>&   board   ,
                    string                  word
                  )
        {
            int r = board.size();
            int c = board[0].size();
            int i = 0;
            int j = 0;
            vector<vector<int>>    visited = vector<vector<int>>(r,vector<int>(c,0));
            
            for( i = 0 ; i < r;i++)
            {
                for( j = 0 ; j < c;j++)
                {
                    
                    if(helper(board,word,0,i,j,visited))
                    {
                        return true;
                    }
                }
            }
            
            return false;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :24 ms, 在所有 cpp 提交中击败了94.24% 的用户
内存消耗 :10.5 MB, 在所有 cpp 提交中击败了90.51%的用户
*/