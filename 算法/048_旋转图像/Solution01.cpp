class Solution
{
    public:
        void rotate(vector<vector<int>>& matrix)
        {
            int rows = matrix.size();
            int cols = rows;
            int i    = 0;
            int j    = 0;
            
            /*1.按行中心对折*/
            for(i = 0 ; i < rows/2 ; i++)
            {
                swap(matrix[i],matrix[rows-1-i]);
            }
            
            /*2.转置*/
            for(i = 0 ; i < rows ; i++)
            {
                for(j=i+1;j<cols;j++)
                {
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
};


/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 cpp 提交中击败了96.63%的用户
内存消耗 :9 MB, 在所有 cpp 提交中击败了83.04%的用户
*/
