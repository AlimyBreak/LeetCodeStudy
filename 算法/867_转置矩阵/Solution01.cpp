class Solution
{
    public:
        vector<vector<int>> transpose(vector<vector<int>>& A)
        {
            vector<vector<int>> ret_val                 ;
            vector<int>         temp                    ;
            int                 i       =   0           ;
            int                 j       =   0           ;
            int                 rows    =   A.size()    ;
            int                 cols    =   0           ;
            if(rows>0)
            {
                cols = A[0].size();
                for(i = 0; i < cols;i++)
                {
                    temp.clear();
                    for(j = 0; j < rows ; j++)
                    {
                        temp.push_back(A[j][i]);
                    }
                    ret_val.push_back(temp);
                }
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :36 ms, 在所有 C++ 提交中击败了75.50% 的用户
内存消耗 :11.5 MB, 在所有 C++ 提交中击败了76.63%的用户
*/