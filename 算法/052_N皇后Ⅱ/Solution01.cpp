

class Solution
{
    
    private:
        void helper(    int&                            ret_val ,
                        vector<string>&                 cur_vs  ,
                        int                             cur_row ,
                        int                             rows    
                   )
        {
            
            if(cur_row == rows)
            {
                ret_val++;
                return;
            }
            
            int k = 0; 
            int i = 0;
            int j = 0;
            int k_valid = 0;
            /*在第cur_row行k列插入一个'Q'*/
            for(k = 0 ; k < rows ; k++) // rows == cols
            {
                k_valid = 1;
                /* 左上对角线方向*/
                for( i = cur_row - 1, j = k-1 ; i >=0 && j >=0;i--,j--)
                {
                    if(cur_vs[i][j] == 'Q')
                    {
                        k_valid = 0;
                        break;
                    }
                }
                if(k_valid==0)
                {
                    continue;
                }
                /*竖直方向*/
                for( i = cur_row-1,j = k; i >=0 ; i--)
                {
                    if(cur_vs[i][j] == 'Q')
                    {
                        k_valid = 0;
                        break;
                    } 
                }
                if(k_valid==0)
                {
                    continue;
                }
                
                /*右上方向*/
                for( i = cur_row-1,j = k+1; i >=0 && j < rows; i--,j++)
                {
                    if(cur_vs[i][j] == 'Q')
                    {
                        k_valid = 0;
                        break;
                    } 
                }
                if(k_valid==0)
                {
                    continue;
                }
                
                cur_vs[cur_row][k] = 'Q';
                helper(ret_val,cur_vs,cur_row+1,rows);
                cur_vs[cur_row][k] = '.';
            }
        }
    
    
    public:
    
        int totalNQueens(int n)
        {
            int ret_val = 0;
            if(n < 1)
            {
                return 0;
            }
            vector<string> cur(n,string(n,'.'));
            helper(ret_val,cur,0,n);
            
            return ret_val;
        
        }
    

};


/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 cpp 提交中击败了92.60% 的用户
内存消耗 :8.5 MB, 在所有 cpp 提交中击败了35.96%的用户
*/