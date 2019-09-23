class Solution
{
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix)
        {
            vector<int>     ret_val             ;
            int             m           = 0     ;
            int             n           = 0     ;
            int             rows_start  = 0     ;
            int             cols_start  = 0     ;
            int             i           = 0     ;
            
            if(matrix.size() > 0)
            {
                m = matrix.size();
                n = matrix[0].size();
                
                while(    (m > 0)
                        &&(n > 0)
                )
                {
                    if(m==1)
                    {
                        for(i = 0; i < n ; i++)
                        {
                            ret_val.push_back(matrix[rows_start][cols_start+i]);
                        }
                        break;
                    }
                    if(n==1)
                    {
                        for(i = 0 ; i < m;i++)
                        {
                            ret_val.push_back(matrix[rows_start+i][cols_start]);
                        }
                        break;
                    }
                    
                    
                    /* up edge */
                    for(i = 0 ; i < n ; i++)
                    {
                        ret_val.push_back(matrix[rows_start][cols_start+i]);
                    }
                    
                    /* right edge */
                    for(i = 1 ; i < m ; i++)
                    {
                        ret_val.push_back(matrix[rows_start+i][cols_start+n-1]);
                    }
                    
                    /* bottom edge*/
                    for(i = cols_start+n-2 ; i >=cols_start ; i--)
                    {
                        ret_val.push_back(matrix[rows_start+m-1][i]);
                    }
                    
                    /* left edge*/
                    for(i = rows_start+m-2; i > rows_start;i--)
                    {
                        ret_val.push_back(matrix[i][cols_start]);
                    }
                    
                    m = m - 2;
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
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :8.6 MB, 在所有 C++ 提交中击败了52.60%的用户
*/