class Solution
{
    private:
        vector<int> ret_val;
        int m;  /* 行数*/
        int n;  /* 列数*/
        int size;
        void __travelMatrix( vector<vector<int>>& vvi , int rows_start)
        {
            int cols_start  =   rows_start;
            int i           =   0;
            if((m<=0)||(n<=0))
            {
                return ;
            }
            if(ret_val.size()>=size)
            {
                return ;
            }
            /* up edge */
            for(i = 0 ; i < n ; i++)
            {
                ret_val.push_back(vvi[rows_start][cols_start+i]);
                if(ret_val.size()>=size)
                {
                    return ;
                }
            }
            
            /* right edge */
            for(i = 1 ; i < m ; i++)
            {
                ret_val.push_back(vvi[rows_start+i][cols_start+n-1]);
                if(ret_val.size()>=size)
                {
                    return ;
                }
            }
            
            /* bottom edge*/
            for(i = cols_start+n-2 ; i >=cols_start ; i--)
            {
                ret_val.push_back(vvi[rows_start+m-1][i]);
                if(ret_val.size()>=size)
                {
                    return ;
                }
            }
            
            /* left edge*/
            for(i = rows_start+m-2; i > rows_start;i--)
            {
                ret_val.push_back(vvi[i][cols_start]);
                if(ret_val.size()>=size)
                {
                    return ;
                }
            }
            
            m = m - 2;
            n = n - 2;
            __travelMatrix(vvi,rows_start+1);
        }
        
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix)
        {
            ret_val.clear();
            if(matrix.size() > 0)
            {
                m = matrix.size();
                n = matrix[0].size();
                size = m*n;
                __travelMatrix(matrix,0);
            }
            return ret_val;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了77.88% 的用户
内存消耗 :8.6 MB, 在所有 C++ 提交中击败了58.52%的用户
*/