class Solution
{
    public:
        vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A)
        {
            vector<vector<int>> ret_val     ;
            vector<int>         temp        ;
            int                 i       = 0 ;
            int                 j       = 0 ;
            for(i=0;i<A.size();i++)
            {
                temp = A[i];
                reverse(temp.begin(), temp.end());
                for(j=0;j<temp.size();j++)
                {
                    temp[j] = !temp[j];
                }
                ret_val.push_back(temp);
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :32 ms, 在所有 C++ 提交中击败了17.27% 的用户
内存消耗 :9.5 MB, 在所有 C++ 提交中击败了68.44%的用户
*/