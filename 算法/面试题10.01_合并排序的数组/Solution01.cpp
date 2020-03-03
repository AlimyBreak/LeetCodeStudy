class Solution
{
    public:
        void merge(vector<int>& A, int m, vector<int>& B, int n)
        {
            
            for( int i = 0;i < n; i++ )
            {
                A[m+i] = B[i];
            }
            
            sort(A.begin(),A.end());
        }
};
/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C++ 提交中击败了28.76% 的用户
内存消耗 :11.5 MB, 在所有 C++ 提交中击败了100.00%的用户
*/

