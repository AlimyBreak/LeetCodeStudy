class Solution
{
    void __fillN4Edge(vector<vector<int>>& vvi,int n,int rows_start,int idx_start)
    {
        int cols_start = rows_start;
        if(n==0)
        {
            return;
        }
        if(n==1)
        {
            vvi[rows_start][cols_start] = idx_start;
            return ;
        }

        if(n==2)
        {
            vvi[rows_start][cols_start]         = idx_start++;
            vvi[rows_start][cols_start+1]       = idx_start++;
            vvi[rows_start+1][cols_start+1]     = idx_start++;
            vvi[rows_start+1][cols_start]       = idx_start;
            
            return ;
        }
        
        /* up edge */
        for(int i = 0 ; i < n ; i++)
        {
            vvi[rows_start][cols_start+i] = idx_start++;
        }
        
        /* right edge */
        for(int i = 1 ; i < n ; i++)
        {
            vvi[rows_start+i][cols_start+n-1] = idx_start++;
        }
        
        /* bottom edge*/
        for(int i = cols_start+n-2 ; i >=cols_start ; i--)
        {
            vvi[rows_start+n-1][i] = idx_start++;
        }
        
        /* left edge*/
        for(int i = rows_start+n-2; i > rows_start;i--)
        {
            vvi[i][cols_start] = idx_start++;
        }
        
        /* tail recursion*/
        __fillN4Edge(vvi,n-2,rows_start+1,idx_start);
    }
    
    public:
        vector<vector<int>> generateMatrix(int n)
        {
            vector<vector<int>> ret_val;
            
            if(n>0)
            {
                vector<int> temp;
                for(int i = 0; i < n ; i++)
                {
                    temp.push_back(0);
                }
                for(int i = 0; i < n ; i++)
                {
                    ret_val.push_back(temp);
                }
                
                __fillN4Edge(ret_val,n,0,1);
            }
            return ret_val;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C++ 提交中击败了68.56% 的用户
内存消耗 :9.1 MB, 在所有 C++ 提交中击败了11.81%的用户
*/