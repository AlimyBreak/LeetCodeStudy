class Solution
{   
    public:
        vector<vector<int>> generateMatrix(int n)
        {
            vector<vector<int>> ret_val;
            int i = 0;
            
            if(n>0)
            {
                vector<int> temp;
                for(i = 0; i < n ; i++)
                {
                    temp.push_back(0);
                }
                for(i = 0; i < n ; i++)
                {
                    ret_val.push_back(temp);
                }
                
                //__fillN4Edge(ret_val,n,0,1);
                int rows_start = 0;
                int idx_start  = 1;
                int cols_start = 0;
                while(n>0)
                {
                    if(n==1)
                    {
                        ret_val[rows_start][cols_start] = idx_start;
                        break;
                    }
                    if(n==2)
                    {
                        ret_val[rows_start][cols_start]         = idx_start++;
                        ret_val[rows_start][cols_start+1]       = idx_start++;
                        ret_val[rows_start+1][cols_start+1]     = idx_start++;
                        ret_val[rows_start+1][cols_start]       = idx_start; 
                        break;
                    }
                    
                    /* up edge */
                    for(i = 0 ; i < n ; i++)
                    {
                        ret_val[rows_start][cols_start+i] = idx_start++;
                    }
                    
                    /* right edge */
                    for(i = 1 ; i < n ; i++)
                    {
                        ret_val[rows_start+i][cols_start+n-1] = idx_start++;
                    }
                    
                    /* bottom edge*/
                    for(i = cols_start+n-2 ; i >=cols_start ; i--)
                    {
                        ret_val[rows_start+n-1][i] = idx_start++;
                    }
                    
                    /* left edge*/
                    for(i = rows_start+n-2; i > rows_start;i--)
                    {
                        ret_val[i][cols_start] = idx_start++;
                    }
                    
                    n = n - 2;
                    rows_start++;
                    cols_start++;
                }
                
                
            }
            
            return ret_val;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了94.85% 的用户
内存消耗 :8.9 MB, 在所有 C++ 提交中击败了51.11%的用户
*/
